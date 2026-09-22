/*
 * :file description:
 * :name: /project51/XPT2046.c
 * :author: 张德志
 * :date created: 2026-09-23 05:41:44
 * :last editor: 张德志
 * :date last edited: 2026-09-23 06:19:43
 */
#include <REGX52.H>

#define XPT2046_CS = P3_5;
#define XPT2046_DCLK = P3_6;
#define XPT2046_DIN = P3_4;
#define XPT2046_DOUT = P3_7;

unsigned int XPT2046_ReadAD(unsigned char Command)
{
    unsigned char i;
    unsigned int ADVALue;
    P3_6 = 0;
    P3_5 = 0;

    for (i = 0; i < 8; i++)
    {
        P3_4 = Command & (0x80 >> i);
        P3_6 = 1;
        P3_6 = 0;
    }

    P3_6 = 1;
    P3_6 = 0;

    for (i = 0; i < 16; i++)
    {
        P3_6 = 1;
        P3_6 = 0;
        if (P3_7)
        {
            ADVALue |= (0x8000 >> i);
        }
    }

    P3_5 = 1;

    return ADVALue >> 8;
}
