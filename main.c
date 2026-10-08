/*
 * :file description:
 * :name: /project51/main.c
 * :author: 张德志
 * :date created: 2026-09-19 15:18:26
 * :last editor: 张德志
 * :date last edited: 2026-10-09 07:25:47
 */
/*
 * main.c — LED 呼吸灯(软件 PWM:渐亮 + 渐暗)
 *
 * 目标芯片: STC89C52RC, 11.0592 / 12 MHz, 12T 模式。
 * LCD 接线见 LCD1602.c 的引脚配置,必须与实际硬件一致。
 */

#include <REGX52.H>
#include "<INTRINS.H>"

void Delayms(unsigned int xms)
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
    while (1)
    {
        P2 = 0xFE;
        Delayms(500);
        P2 = 0xFD;
        Delayms(500);
        P2 = 0xFB;
        Delayms(500);
        P2 = 0xF7;
        Delayms(500);
        P2 = 0xEF;
        Delayms(500);
        P2 = 0xDF;
        Delayms(500);
        P2 = 0xBF;
        Delayms(500);
        P2 = 0x7F;
        Delayms(500);
    }
}