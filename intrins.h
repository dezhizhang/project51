/*
 * intrins.h — Keil C51 <INTRINS.H> 兼容文件(SDCC 版)
 *
 * 提供教程里常用的内部函数,函数名与 Keil 完全一致,教程代码直接抄:
 *   _nop_()               空一个机器周期(1us @ 12MHz/12T)
 *   _crol_(val, n)        字节循环左移 n 位(流水灯核心)
 *   _cror_(val, n)        字节循环右移 n 位
 *   _irol_ / _iror_       16 位循环移位
 *   _lrol_ / _lror_       32 位循环移位
 */

#ifndef __INTRINS_H__
#define __INTRINS_H__

/* 空操作:编译成一条 NOP 指令 */
#define _nop_() __asm__("nop")

/* ---- 字节(8位)循环移位 ---- */
static unsigned char _crol_(unsigned char val, unsigned char n)
{
    n &= 7;
    if (n == 0) return val;
    return (unsigned char)((val << n) | (val >> (8 - n)));
}

static unsigned char _cror_(unsigned char val, unsigned char n)
{
    n &= 7;
    if (n == 0) return val;
    return (unsigned char)((val >> n) | (val << (8 - n)));
}

/* ---- 整数(16位)循环移位 ---- */
static unsigned int _irol_(unsigned int val, unsigned char n)
{
    n &= 15;
    if (n == 0) return val;
    return (val << n) | (val >> (16 - n));
}

static unsigned int _iror_(unsigned int val, unsigned char n)
{
    n &= 15;
    if (n == 0) return val;
    return (val >> n) | (val << (16 - n));
}

/* ---- 长整数(32位)循环移位 ---- */
static unsigned long _lrol_(unsigned long val, unsigned char n)
{
    n &= 31;
    if (n == 0) return val;
    return (val << n) | (val >> (32 - n));
}

static unsigned long _lror_(unsigned long val, unsigned char n)
{
    n &= 31;
    if (n == 0) return val;
    return (val >> n) | (val << (32 - n));
}

#endif /* __INTRINS_H__ */
