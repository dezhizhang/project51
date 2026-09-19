/*
 * sdcc_intellisense.h — 仅供 VS Code IntelliSense 使用,SDCC 编译时完全忽略
 *
 * SDCC 的专有关键字(__sfr/__sbit/__at/__interrupt 等)不是标准 C,
 * VS Code 的 C/C++ 分析器不认识会报红。这里把它们定义成"空",
 * 让分析器把  __sfr __at (0x90) P1;  看成普通声明,红线全消。
 */

#define __sfr
#define __sbit
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
