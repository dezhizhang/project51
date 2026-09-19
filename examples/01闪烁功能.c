/*
 * :file description: 
 * :name: /project51/examples/01闪烁功能.c
 * :author: 张德志
 * :date created: 2026-09-19 15:18:26
 * :last editor: 张德志
 * :date last edited: 2026-09-19 16:52:53
 */
/*
 * main.c — 51 单片机入门程序:LED 流水灯
 *
 * 目标芯片: STC89C52RC(兼容 AT89C52 / STC12C5A 等标准 8051 内核)
 * 晶振:   11.0592 MHz 或 12 MHz 均可(软件延时,不要求精确)
 *
 * 硬件说明: P1 口接 8 个 LED(绝大多数 51 开发板 P1 整组接灯)
 *           低电平点亮(共阳接法:引脚输出 0 → 对应 LED 亮)
 *           如果你的板子是高电平点亮,把 main 里的取反逻辑改一下即可
 */

#include <8052.h>    /* SDCC 自带的 8052 内核寄存器定义(P0/P1/P2/P3...) */
#include <REGX52.H>
#include <INTRINS_H>
#define LED_PORT P1  /* LED 所在端口,板子不同可改成 P2 / P0 */


void Delay500ms() 
{
    unsigned char i,j, k;

    _nop_();
    i=4;
    j=205;
    k=187;

    do{
        do {
            while(--k);

        } while(--j);
    } while(--i);

}


void main(void)
{
    while(1) {
        P2=0xFE;
        Delay500ms();
        P2=0xFF;
        Delay500ms();
    }
}
