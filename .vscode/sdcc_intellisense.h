/*
 * sdcc_intellisense.h — 仅供 VS Code IntelliSense / clangd 使用,SDCC 编译时完全忽略
 *
 * SDCC 专有关键字不是标准 C,编辑器的 C 分析器不认识会报红。
 * 策略:把存储类关键字翻译成普通声明 ——
 *   __sfr __at (0x90) P1;   →   extern int P1;   (合法声明,分析器满意)
 * 这样寄存器名全部可解析、可跳转、可补全。
 */

#define __sfr  extern int
#define __sbit extern int
#define __at(x)
#define __interrupt(x)
#define __using(x)
#define __naked
#define __reentrant
#define __critical
#define __data
#define __idata
#define __pdata
#define __xdata
#define __code
#define __sram
