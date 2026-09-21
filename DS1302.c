/*
 * :file description:
 * :name: /project51/DS1302.c
 * :author: 张德志
 * :date created: 2026-09-22 04:50:53
 * :last editor: 张德志
 * :date last edited: 2026-09-22 05:49:13
 */
#include <REGX52.H>

// Keil 的 sbit DS1302_SCLK=P3^6; 是专有语法,SDCC 用内置位名 P3_6 代替
#define DS1302_SCLK P3_6
#define DS1302_IO P3_4
#define DS1302_CE P3_5

void DS1302_Init(void)
{
    DS1302_CE = 0;
    DS1302_SCLK = 0;
}

void DS1302_WriteByte(unsigned char Command, unsigned char Data)
{

    unsigned char i;
    DS1302_CE = 1;

    for (i = 0; i < 8; i++)
    {
        DS1302_IO = Command & (0x01 << i);
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
    }

    for (i = 0; i < 8; i++)
    {
        DS1302_IO = Data & (0x01 << i);
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
    }
    DS1302_CE = 0;
}

unsigned char DS1302_ReadByte(unsigned char Command)
{
    unsigned char i;
    unsigned char Data = 0x00;
    DS1302_CE = 1;
    for (i = 0; i < 8; i++)
    {
        DS1302_IO = Command & (0x01 << i);
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
    }
    DS1302_IO = 0;
    for (i = 0; i < 8; i++)
    {
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
       
        if (DS1302_IO)
        {
            Data |= (0x01 << i);
        }
    }
    DS1302_CE=0;
    return Data;
}
