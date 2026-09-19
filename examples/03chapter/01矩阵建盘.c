/*
 * :file description:
 * :name: /project51/examples/03chapter/01矩阵建盘.c
 * :author: 张德志
 * :date created: 2026-09-19 15:18:26
 * :last editor: 张德志
 * :date last edited: 2026-09-20 07:07:32
 */
/*
 * main.c — LCD1602 显示测试
 *
 * 目标芯片: STC89C52RC, 11.0592 / 12 MHz, 12T 模式。
 * LCD 接线见 LCD1602.c 的引脚配置,必须与实际硬件一致。
 */

#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
void main(void)
{
  LCD_Init();

  while (1)
  {
    /* LCD 会保持显示,无需反复清屏或重写。 */
    KeyNum = MatrixKey();

    if (KeyNum)
    {
      LCD_ShowNum(2, 1, KeyNum,2);
    }
  }
}
