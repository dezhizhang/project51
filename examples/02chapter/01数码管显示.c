/*
 * :file description:
 * :name: /project51/examples/02chapter/01数码管显示.c
 * :author: 张德志
 * :date created: 2026-09-19 15:18:26
 * :last editor: 张德志
 * :date last edited: 2026-09-19 22:54:28
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

#include <8052.h> /* SDCC 自带的 8052 内核寄存器定义(P0/P1/P2/P3...) */
#include <REGX52.H>
#include <INTRINS_H>
#define LED_PORT P1 /* LED 所在端口,板子不同可改成 P2 / P0 */


unsigned char NexieTable[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x7D,0x7F,0x7F,0x6};

void Nexie(unsigned char location, unsigned char number)
{
  switch (location)
  {
  case 1:
    P2_4 = 1;
    P2_3 = 1;
    P2_2 = 1;
    break;
  case 2:
    P2_4 = 1;
    P2_3 = 1;
    P2_2 = 0;
    break;
  case 3:
    P2_4 = 1;
    P2_3 = 0;
    P2_2 = 1;
    break;
  case 4:
    P2_4 = 1;
    P2_3 = 0;
    P2_2 = 1;
    break;
  case 5:
    P2_4 = 0;
    P2_3 = 1;
    P2_2 = 1;
    break;
  case 6:
    P2_4 = 0;
    P2_3 = 1;
    P2_2 = 0;
    break;
  case 7:
    P2_4 = 0;
    P2_3 = 0;
    P2_2 = 1;
    break;
  case 8:
    P2_4 = 0;
    P2_3 = 0;
    P2_2 = 0;
    break;
  }
  P0 = NexieTable[number];
}

void main(void)
{
  while (1)
  {
   Nexie(7,8);
  }
}
