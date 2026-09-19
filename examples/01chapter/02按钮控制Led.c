#include <8052.h> /* SDCC 自带的 8052 内核寄存器定义(P0/P1/P2/P3...) */
#include <REGX52.H>
#include <INTRINS_H>
#define LED_PORT P1 /* LED 所在端口,板子不同可改成 P2 / P0 */



void main()
{
    while (1)
    {
        if (p3_1 == 0)
        {
            P2_0 = 0;
        }
        else
        {
            P2_0 = 1;
        }
    }
}