/*
 * :file description:
 * :name: /project51/main.c
 * :author: 张德志
 * :date created: 2026-09-19 15:18:26
 * :last editor: 张德志
 * :date last edited: 2026-09-22 22:18:13
 */
/*
 * main.c — LED 呼吸灯(软件 PWM:渐亮 + 渐暗)
 *
 * 目标芯片: STC89C52RC, 11.0592 / 12 MHz, 12T 模式。
 * LCD 接线见 LCD1602.c 的引脚配置,必须与实际硬件一致。
 */

#include <REGX52.H>
#include "LCD1602.h"

unsigned char Second;

int main()
{
  LCD_Init();
  LCD_ShowChar(2,3,'A');
  while(1) {
    
  }
}