/*
 * :file description:
 * :name: /project51/examples/03chapter/02动态数码管.c
 * :author: 张德志
 * :date created: 2026-09-19 15:18:26
 * :last editor: 张德志
 * :date last edited: 2026-10-10 22:55:38
 */
/*
 * main.c — LED 呼吸灯(软件 PWM:渐亮 + 渐暗)
 *
 * 目标芯片: STC89C52RC, 11.0592 / 12 MHz, 12T 模式。
 * LCD 接线见 LCD1602.c 的引脚配置,必须与实际硬件一致。
 */

#include <REGX52.H>
#include "<INTRINS.H>"

void Delay(unsigned char xms)
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

void Nixie(unsigned char Location, unsigned char Number)
{
    unsigned char NixieArr[9] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
    switch (Location)
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
        P2_2 = 0;
        break;
    case 5:
        P2_4 = 0;
        P2_3 = 0;
        P2_2 = 1;
        break;
    case 6:
        P2_4 = 0;
        P2_3 = 1;
        P2_2 = 0;
    case 7:
        P2_4 = 0;
        P2_4 = 0;
        P2_4 = 1;
        break;
    case 8:
        P2_4 = 0;
        P2_3 = 0;
        P2_2 = 0;
        break;
    }

    P0 = NixieArr[Number];
    Delay(1);
    P0 = 0x00;
}

void main()
{

    while (1)
    {
        Nixie(1, 1);
        Delay(1);
        Nixie(2, 2);
        Delay(1);
        Nixie(3, 3);
        Delay(1);
    }
}
