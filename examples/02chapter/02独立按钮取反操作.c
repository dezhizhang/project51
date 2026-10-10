/*
 * :file description:
 * :name: /project51/examples/02chapter/03独立按钮取反操作.c
 * :author: 张德志
 * :date created: 2026-09-19 15:18:26
 * :last editor: 张德志
 * :date last edited: 2026-10-10 21:13:07
 */
/*
 * main.c — LED 呼吸灯(软件 PWM:渐亮 + 渐暗)
 *
 * 目标芯片: STC89C52RC, 11.0592 / 12 MHz, 12T 模式。
 * LCD 接线见 LCD1602.c 的引脚配置,必须与实际硬件一致。
 */

#include <REGX52.H>
#include "<INTRINS.H>"

void Delay(unsigned int xms)
{
    unsigned char i, j;
    while (xms)
    {
        i = 2;
        j = 239;
        _nop_();
        do
        {
            while (--j)
                ;
        } while (--i);
        xms--;
    }
}

void main()
{

    unsigned char led = 0;
    while (1)
    {
        if (P3_1 == 0)
        {
            Delay(10);
            while (P3_1 == 0)
                ;
            Delay(10);
            led = !led;
            P2_0 = led;
        }
    }
}
