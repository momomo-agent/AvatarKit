# iOS 私有框架逆向方法论

> 从 AvatarKit.framework 逆向实战中提炼，持续迭代

## 核心原则

**证据，不是猜测。**

每个结论必须指回一个具体的地址、符号、或指令。指不回去的标 `(unconfirmed)` 或 `(inferred)`，不混在确认的结论里。

反面例子：tongue correction 的 7 个 blendshape，第一版从反汇编"看起来像"推导，写了 jawOpen/mouthLeft/mouthRight。用 `nm` 查符号地址后发现实际是 mouthClose/mouthPressLeft/mouthPressRight。猜错了三个。

正面例子：blink correction 的常量，从 `__TEXT,__const` 段 hex 解码得到精确的 1.1 和 2/3，不是"看起来像 gamma 曲线所以大概是 2/3"。

## 工具链

### fwrev CLI（自研）

```bash
# 侦察
fwrev find-fw <name>                    # 定位框架二进制
fwrev classes <binary>                  # 列所有 ObjC 类
fwrev methods <binary> <class>          # 列类的方法
fwrev ivars <binary> <class>            # 列 ivars + type encoding
fwrev hierarchy <binary> <class>        # 类继承链
fwrev symbols <binary> [filter]         # nm 符号表

# 分析
fwrev disasm <binary> <method>          # 反汇编
fwrev disasm <binary> <method> --annotate  # 反汇编 + 自动注释引用
fwrev refs <binary> <method>            # 提取所有外部引用（符号/常量/字符串）+ 证据链
fwrev resolve <binary> <addr>           # 地址 → 符号/常量/字符串
fwrev flow <binary> <method>            # 控制流分析
fwrev callers <binary> <method>         # 谁调用了这个方法
fwrev struct <binary> <ivar>            # 从 type encoding 解析结构体
fwrev consts <binary> <addr> [count]    # 解码常量段
```

### 底层工具（fwrev 内部使用）

- `otool -tV` — ARM64 反汇编
- `otool -oV` — ObjC 元数据
- `otool -s __TEXT __const` — 常量段 hex dump
- `nm` — 符号表
- `strings -t x` — 带地址的字符串提取

## 方法步骤

### Phase 0: 建立覆盖地图

**在写任何代码之前，先建全局地图。**

这不是可选步骤。没有地图就开始逆向 = 盲人摸象。

```bash
# 1. 全量类 + 方法数统计
fwrev classes <binary> | while read cls; do
  count=$(fwrev methods <binary> "$cls" 2>/dev/null | wc -l)
  echo "$count $cls"
done | sort -rn

# 2. 按功能域分组（前缀/命名模式）
# 3. 标记状态：✅已还原 / 🔍已探索 / 📋已侦察 / ❌未探索
# 4. 画出核心数据流（输入→处理→输出）
# 5. 确定优先级：先覆盖关键路径，再扩展
```

覆盖地图要持续更新。每次逆向完一个类/方法，更新状态和发现。

地图的价值：
- 知道总量有多大（AvatarKit: 94 核心类, 1403 方法）
- 知道自己在哪（6/94 = 6.4%，但覆盖了完整数据流）
- 知道下一步该去哪（按数据流优先级排序）
- 防止在不重要的类上浪费时间

### Phase 1: 侦察（每个目标类必做）

```bash
fwrev hierarchy <binary> <class>    # 继承链
fwrev ivars <binary> <class>        # 数据结构
fwrev methods <binary> <class>      # 能力清单
```

这三个命令给出类的完整轮廓：它是什么（继承）、它有什么（ivars）、它能做什么（methods）。

### Phase 2: 结构还原

优先从 type encoding 提取字段名和类型：

```bash
fwrev struct <binary> <ivar>
```

Type encoding 是最可靠的证据源——编译器生成的，不会骗人。但 SIMD 类型在 encoding 里是 opaque 的，需要从反汇编补充。

补充 SIMD 类型的方法：
- `ldp q, q, [ptr, #offset]` → 128-bit 读取 = simd_float4 或 simd_quatf
- `ldr s, [ptr, #offset]` → 32-bit = Float
- `ldr d, [ptr, #offset]` → 64-bit = Double
- `ldrb w, [ptr, #offset]` → 8-bit = Bool/UInt8

### Phase 3: 行为分析

```bash
# 先看引用全景——一个命令拿到所有外部依赖
fwrev refs <binary> <method>

# 再看带注释的反汇编——每条指令的引用自动解析
fwrev disasm <binary> <method> --annotate

# 控制流分析——分支和跳转目标
fwrev flow <binary> <method>
```

`refs` 是最高效的入口。它一次性输出：
- 所有符号引用（调用了谁、引用了什么全局变量）
- 所有常量（自动 decode float/double）
- 所有字符串引用
- 每个都带 `evidence` 行

### Phase 4: 地址解析

遇到不确定的地址，用 `resolve` 查：

```bash
fwrev resolve <binary> 0xa5590
# → kind: symbol
#   value: _AVTBlendShapeLocationMouthClose
#   evidence: nm: a5590 s _AVTBlendShapeLocationMouthClose
```

三种解析路径：
1. **符号** — nm 符号表精确匹配或最近匹配
2. **常量** — `__TEXT,__const` 段 hex → float32/float64 自动解码
3. **字符串** — `strings -t x` 地址匹配

### Phase 5: 还原为代码

把逆向结果写成可编译的 Swift 代码。要求：
- 每个常量标注来源地址
- 每个结构体字段标注 offset 和证据
- 不确定的部分标注 `(inferred)` 或 `(unconfirmed)`
- 代码注释里写清楚逆向方法（哪条指令、哪个符号）

### Phase 6: 更新覆盖地图

每次完成一个类/方法的逆向，更新 `coverage-map.md`：
- 状态升级（❌→📋→🔍→✅）
- 记录关键发现
- 更新数据流图
- 调整下一步优先级

## ARM64 指令速查

### 数据访问
```
ldr x8, [x0, #0x18]     从对象偏移 0x18 读 8 字节（指针/Int64）
ldr w8, [x0, #0x18]     从偏移 0x18 读 4 字节（Int32/Float via w reg）
ldr s0, [x0, #0x18]     从偏移 0x18 读 Float（到 SIMD 寄存器）
ldr d0, [x0, #0x18]     从偏移 0x18 读 Double
ldrb w8, [x0, #0x30]    从偏移 0x30 读 1 字节（Bool/UInt8）
ldp q0, q1, [x0, #0x10] 从偏移 0x10 读 2×128bit（simd_float4 对）
```

### 地址计算
```
adrp x8, N ; 0xABCDE    加载页地址（高位）
add x8, x8, #0x123      加页内偏移 → 完整地址 0xABCDE + 0x123
ldr x8, [x8, #0x456]    从计算地址加载（GOT 间接引用）
ldr d0, [x8, #0x456]    从计算地址加载常量（__TEXT,__const）
```

### 分支
```
bl 0xABCDE               函数调用（branch with link）
b 0xABCDE                无条件跳转
b.eq / b.ne              条件跳转（equal / not equal）
cbz x0, 0xABCDE          x0==0 则跳转
cbnz x0, 0xABCDE         x0!=0 则跳转
tbnz w0, #0, 0xABCDE     bit 0 非零则跳转
```

### 浮点
```
fmov s0, #1.0            立即数加载
fcmp s0, #0.0            比较
fmul / fadd / fsub       算术
fminnm / fmaxnm          min/max（NaN 安全）
fcvt d0, s0              float→double 转换
fmadd s0, s1, s2, s3     s0 = s1*s2 + s3（fused multiply-add）
```

## 证据链模板

每个逆向结论用这个格式记录：

```
结论: [具体结论]
证据: [指令地址] [指令内容]
验证: [fwrev 命令] → [输出]
```

示例：
```
结论: BlinkCorrection scale = 1.1
证据: 0x32f04 ldr d1, [x8, #0xd90]
验证: fwrev resolve AvatarKit 0x65d90
  → kind: constant
  → float64: 1.1
  → evidence: __TEXT,__const @ 0x65d90: 9999999a 3ff19999
```

## 常见陷阱

1. **SIMD 类型在 type encoding 里是 opaque 的** — 不要假设 offset，从反汇编确认
2. **otool 注释不完整** — 它会标注一些 `literal pool symbol address`，但很多 adrp+ldr 没有注释
3. **struct 解析器对 opaque 类型会算错后续 offset** — 用反汇编交叉验证
4. **方法边界** — otool 不标注方法结束，用下一个 `[-+][` 开头的行判断
5. **cold 路径** — `.cold.1` 后缀是异常/错误路径，不要当成下一个方法的开始
6. **GOT 间接引用** — `ldr x8, [x8, #offset]` 可能是 GOT 指针，实际值需要再解一层
7. **字段名 ≠ 你以为的名字** — "trackingFlag" 实际叫 "cameraSpace"，type encoding 是唯一真相
