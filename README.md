# 51 单片机项目(C 语言 + SDCC + stcgal)

macOS 下的 8051(51 单片机)开发项目,纯命令行工作流:编译、烧录、运行一条命令搞定。

- **编译器**: [SDCC](http://sdcc.sourceforge.net/) —— 开源 8051 C 编译器
- **烧录器**: [stcgal](https://github.com/grigorig/stcgal) —— 开源 STC 单片机烧录工具
- **默认目标芯片**: STC89C52RC(兼容各类标准 51 内核板子)

## 环境安装(一次性)

```bash
brew install sdcc                      # 编译器
python3 -m pip install stcgal          # 烧录工具(依赖 pyserial,会自动装)
```

## 快速上手(完整执行流程)

```bash
# 1. 编译,生成 build/main.hex
make

# 2. 插上板子,烧录到单片机
#    看到 "Waiting for MCU" 提示时:给板子断电再重新上电(或按 RESET)
make flash

# 3. 运行程序 —— 51 单片机烧录完复位即自动执行,一条命令烧录+运行
make run

# 4.(可选)打开串口终端看板子输出,按 Ctrl+] 退出
make monitor

# 5. 改完代码重新编译前清理旧产物
make clean
```

> 没检测到串口时手动指定:`make flash PORT=/dev/cu.usbserial-XXXX`

## 常用命令速查

| 命令 | 作用 |
|---|---|
| `make` | 编译,生成 `build/main.hex` |
| `make flash` | 编译 + 烧录到板子 |
| `make run` | 烧录并让程序在板子上运行(51 烧录完复位即自动跑) |
| `make monitor` | 打开串口终端(9600 波特率),看串口输出,`Ctrl+]` 退出 |
| `make clean` | 清理构建产物 |

串口不对时手动指定:`make flash PORT=/dev/cu.xxxxxx`

## 烧录流程说明(STC 系列冷启动烧录)

1. 板子插 USB,运行 `make flash`
2. stcgal 显示 `Waiting for MCU, please power cycle device` 时,
   **给板子断电再重新上电**(或按 RESET 键)—— STC 芯片要靠冷启动进入 ISP 烧录模式
3. 烧录完成后芯片自动复位,用户程序即开始运行

## 修改配置

- **换芯片**:改 Makefile 里的 `MCU`(stc89 / stc12 / stc15 / stc8 等 stcgal 协议名),
  例如 `make flash MCU=stc15`
- **换 LED 端口**:改 `main.c` 里的 `LED_PORT`

## macOS 串口驱动

板子上的 USB 转串口芯片大多是 CH340/CH341:

- macOS 13+ 一般自带驱动,插上即出现 `/dev/cu.usbserial-XXXX` 或 `/dev/cu.wchusbserialXXXX`
- 没出现设备的话,去 [WCH 官网](https://www.wch.cn/downloads/CH341SER_MAC_ZIP.html) 装驱动后重启

## 抄 Keil 教程代码(普中/江科大)对照表

本项目用 SDCC,教程用 Keil C51。项目里的 `REGX52.H` 已做了桥接,
`#include <REGX52.H>` 可直接用,寄存器名(P0~P3、P1_0、TF0、EA、TR2...)两边一致。
仅两种写法需要手动翻译:

| 用途 | Keil 教程写法 | SDCC 写法(本项目) |
|---|---|---|
| 自定义位 | `sbit LED1 = P2^0;` | `__sbit __at(0xA0) LED1;`(口地址:P1=0x90,P2=0xA0,P3=0xB0,位 n = 口地址+n) |
| 中断函数 | `void isr() interrupt 1` | `void isr(void) __interrupt(1)` |

> 捷径:SDCC 内置了 `P2_0`~`P2_7` 全部位名,教程里 `P2_0 = 0;` 直接抄,不用声明 sbit。

## 常见问题

**`make: stcgal: No such file or directory`**
stcgal 装在 anaconda 目录,老终端窗口的 PATH 没刷新。新开一个终端窗口,或执行 `source ~/.zshrc`。
(Makefile 已做兜底,多数情况会自动找到 stcgal,不用管这条。)

**`未检测到串口设备`**
1. 检查 USB 线是不是**纯充电线**(最常见!必须用数据线)
2. 换个 USB 口/绕开转接器直插
3. 手动指定:`make flash PORT=/dev/cu.usbserial-120`

**烧录一直卡在 `Waiting for MCU`**
stcgal 等握手时,按一下板子 RESET 键,或把板子 USB 拔了重插(STC 靠冷启动进 ISP 模式)。

## 项目结构

```
project51/
├── main.c      # 源码(当前:LED 流水灯)
├── Makefile    # 编译 / 烧录 / 运行 / 串口监视
└── build/      # 构建产物(git 忽略)
```
