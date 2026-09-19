# ================= 51 单片机项目 Makefile =================
# 工具链: SDCC(编译) + stcgal(烧录)
#
# 常用命令:
#   make              编译,生成 build/main.hex
#   make flash        编译 + 烧录到板子(可加 PORT=/dev/cu.xxx 指定串口)
#   make run          烧录并让程序在板子上运行(51 烧录完复位即跑)
#   make monitor      打开串口终端(9600),看板子串口输出
#   make clean        清理构建产物

# 目标芯片 —— stcgal 协议名,按实际芯片改:
#   stc89 (STC89/90 系列,最常见) | stc12 | stc12a | stc15 | stc8 ...
MCU  ?= stc89

# 串口 —— 不指定时自动探测 USB 串口设备(CH340/CP2102/FTDI)
PORT ?= $(shell ls /dev/cu.wchusbserial* /dev/cu.usbserial* /dev/cu.usbmodem* 2>/dev/null | head -n 1)

TARGET  := main
BUILD   := build
HEX     := $(BUILD)/$(TARGET).hex
IHX     := $(BUILD)/$(TARGET).ihx

CC      := sdcc
CFLAGS  ?= -mmcs51 --model-small --std-c99 -I.
PACKIHX := packihx

# stcgal 查找:优先 PATH,找不到就到常见安装位置兜底
# (避免终端 PATH 未刷新时 make 报 "stcgal: No such file or directory")
STCGAL := $(shell command -v stcgal 2>/dev/null || ls /opt/homebrew/anaconda3/bin/stcgal /opt/homebrew/bin/stcgal /usr/local/bin/stcgal 2>/dev/null | head -n 1)
PYBIN  := $(if $(STCGAL),$(dir $(STCGAL))python3,python3)   # 和 stcgal 同目录的 python(带 pyserial)

MON_BAUD ?= 9600

SRC := $(wildcard *.c)
OBJ := $(SRC:%.c=$(BUILD)/%.rel)

.PHONY: all flash run monitor clean help

all: $(HEX)
	@echo ">>> $(HEX) 就绪(已是最新)。烧录: make run | 强制重编: make clean && make"

$(BUILD):
	mkdir -p $(BUILD)

# SDCC 一次只能编译一个源文件:先各自编译成 .rel(-c),再统一链接
$(BUILD)/%.rel: %.c | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

# 链接所有 .rel 生成 .ihx(显式指定输出名,否则会按第一个 .rel 命名)
$(IHX): $(OBJ) | $(BUILD)
	$(CC) $(CFLAGS) -o $(IHX) $(OBJ)

# 把 SDCC 的 ihx 转成标准 Intel HEX(烧录工具通吃这个格式)
$(HEX): $(IHX)
	$(PACKIHX) $(IHX) > $(HEX)
	@echo ">>> 已生成 $(HEX)"

# 烧录。注意: stcgal 会先等待单片机握手,
# 看到提示后需要给板子「断电 → 重新上电」(或按 RESET)才开始烧写
flash: $(HEX)
ifeq ($(STCGAL),)
	@echo "!!! 找不到 stcgal,请先安装: python3 -m pip install stcgal"
	@exit 1
endif
ifeq ($(PORT),)
	@echo "!!! 未检测到串口设备。请确认:"
	@echo "    1. 板子已通过 USB 插好"
	@echo "    2. macOS 需装 CH340 驱动(WCH 官网下载)"
	@echo "    3. 或手动指定: make flash PORT=/dev/cu.xxxxxx"
	@exit 1
endif
	@echo ">>> 烧录到 $(PORT)(协议: $(MCU))"
	@echo ">>> 提示: 命令等待握手时,请给板子断电再上电(或按 RESET)"
	$(STCGAL) -P $(MCU) -p $(PORT) $(HEX)

# 51 单片机「运行」= 烧录完成芯片复位后自动执行用户程序
run: flash
	@echo ""
	@echo ">>> 烧录完成,程序已在板子上运行(LED 应开始流水闪烁)"
	@echo ">>> 若没反应: 按一下 RESET 键或断电重新上电"

monitor:
ifeq ($(PORT),)
	@echo "!!! 未检测到串口设备,请插好板子或手动指定: make monitor PORT=/dev/cu.xxxxxx"
	@exit 1
endif
	$(PYBIN) -m serial.tools.miniterm $(PORT) $(MON_BAUD)

clean:
	rm -rf $(BUILD)
