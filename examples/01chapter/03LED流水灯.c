/*
 * main.c — LED 呼吸灯(软件 PWM:渐亮 + 渐暗)
 *
 * 目标芯片: STC89C52RC, 11.0592 / 12 MHz, 12T 模式。
 * LCD 接线见 LCD1602.c 的引脚配置,必须与实际硬件一致。
 */

#include <REGX52.H>
#include "<INTRINS.H>"

void Delay500ms()
{
    unsigned char i, j, k;

    _nop_();

    i = 4;
    j = 205;
    k = 187;

    do
    {
        do
        {
            while (--k)
                ;
        } while (--j);
    } while (--i);
}

void main()
{
    while (1)
    {
        P2 = 0xFE;
        Delay500ms();
        P2 = 0xFD;
        Delay500ms();
        P2 = 0xFB;
        Delay500ms();
        P2 = 0xF7;
        Delay500ms();
        P2 = 0xEF;
        Delay500ms();
        P2 = 0xDF;
        Delay500ms();
        P2 = 0xBF;
    }
}