/*
 * :file description:
 * :name: /project51/examples/04chapter/01呼吸灯效果.c
 * :author: 张德志
 * :date created: 2026-09-19 15:18:26
 * :last editor: 张德志
 * :date last edited: 2026-09-23 05:33:37
 */
/*
 * main.c — LED 呼吸灯(软件 PWM:渐亮 + 渐暗)
 *
 * 目标芯片: STC89C52RC, 11.0592 / 12 MHz, 12T 模式。
 * LCD 接线见 LCD1602.c 的引脚配置,必须与实际硬件一致。
 */

#include <REGX52.H>
#include "LCD1602.h"

#define LED P2_0

void Delay(unsigned int t)
{
  while (t--)
    ;
}

int main()
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
    for (Time = 100; Time > 0; Time--)
    {
      for (i = 0; i < 20; i++)
      {
        LED = 0;
        Delay(Time);
        LED = 1;
        Delay(100 - Time);
      }
    }
  }
}