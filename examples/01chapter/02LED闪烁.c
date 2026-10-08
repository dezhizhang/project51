/*
 * :file description: 
 * :name: /project51/examples/01chapter/02LED闪烁.c
 * :author: 张德志
 * :date created: 2026-10-09 06:59:39
 * :last editor: 张德志
 * :date last edited: 2026-10-09 06:59:50
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
        P2 = 0xFF;
        Delay500ms();
    }
}