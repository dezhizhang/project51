/*
 * REGX52.H — Keil C51 兼容桥接头文件(SDCC 版)
 *
 * 普中/江科大等 51 教程代码开头都是 #include <REGX52.H>(Keil 专用),
 * 本项目编译器是 SDCC,没有这个文件。本文件把 Keil 的寄存器命名桥接到
 * SDCC 自带的 <8052.h> —— 两边的名字几乎完全一致(P0~P3、P1_0、TF0、
 * EA、CY、TR2 等),所以教程代码不用改寄存器名,直接编译。
 *
 * ── Keil 写法 → SDCC 写法 对照(写自己代码时用到) ──────────────
 *   Keil:  sbit LED1 = P2^0;          SDCC: __sbit __at(0xA0) LED1;
 *                                       (P2.0 地址 = 0xA0;P1 口是 0x90,
 *                                        P2 是 0xA0,P3 是 0xB0,位 n = 口地址 + n)
 *   Keil:  void isr() interrupt 1     SDCC: void isr(void) __interrupt(1)
 *
 *   小技巧:SDCC 已内置 P2_0~P2_7 等全部位名,像教程里 "P2_0 = 0;" 这种
 *   代码不用声明 sbit,直接用!
 * ────────────────────────────────────────────────────────────────
 */

#ifndef __REGX52_H__
#define __REGX52_H__

#include <8052.h>    /* SDCC 的 8052 内核寄存器定义,名字与 Keil 一致 */

#endif /* __REGX52_H__ */
