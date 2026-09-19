/*
 * :file description:
 * :name: /project51/main.c
 * :author: 张德志
 * :date created: 2026-09-19 15:18:26
 * :last editor: 张德志
 * :date last edited: 2026-09-20 05:37:14
 */
/*
 * main.c — LCD1602 显示测试
 *
 * 目标芯片: STC89C52RC, 11.0592 / 12 MHz, 12T 模式。
 * LCD 接线见 LCD1602.c 的引脚配置,必须与实际硬件一致。
 */

#include "LCD1602.h"


void main(void) {
  LCD_Init();
  LCD_ShowString(1,1,"hello world");
  LCD_ShowChar(2,1,'A');

  while (1) {
    /* LCD 会保持显示,无需反复清屏或重写。 */
  }
}
