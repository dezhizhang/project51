/*
 * :file description:
 * :name: /project51/main.c
 * :author: 张德志
 * :date created: 2026-09-19 15:18:26
 * :last editor: 张德志
 * :date last edited: 2026-09-21 23:12:52
 */
/*
 * main.c — LED 呼吸灯(软件 PWM:渐亮 + 渐暗)
 *
 * 目标芯片: STC89C52RC, 11.0592 / 12 MHz, 12T 模式。
 * LCD 接线见 LCD1602.c 的引脚配置,必须与实际硬件一致。
 */

#include <REGX52.H>

/* SDCC 不支持 Keil 的 sbit RCK=P3^5; 专有语法,直接用内置位名 */
#define LED P2_0
// #define SCK P3_6
// #define SER P3_4

void Delay(unsigned int t)
{
  while (t--);
}

void main(void)
{
  unsigned char Time, i;
  while (1)
  {
    for (Time = 0; Time < 100; Time++)
    {
      for (i = 0; i < 20; i++)
      {
        LED = 0;
        Delay(Time);
        LED = 1;
        Delay(100 - Time);
      }
    }

    for(Time=100;Time > 0;Time--) {
      for(i=0;i < 20;i++) {
         LED = 0;
        Delay(Time);
        LED = 1;
        Delay(100 - Time);
      }
    }

  }
}
