/*
 * :file description: 
 * :name: /project51/Nexie.c
 * :author: 张德志
 * :date created: 2026-09-20 04:30:02
 * :last editor: 张德志
 * :date last edited: 2026-09-20 04:30:16
 */

#include <8052.h> /* SDCC 自带的 8052 内核寄存器定义(P0/P1/P2/P3...) */
#include <REGX52.H>

#include <INTRINS_H>
#include "Delay.h"

unsigned char NexieTable[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x7D, 0x7F, 0x7F, 0x6};

void Nexie(unsigned char location, unsigned char number)
{
  switch (location)
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
    P2_2 = 1;
    break;
  case 5:
    P2_4 = 0;
    P2_3 = 1;
    P2_2 = 1;
    break;
  case 6:
    P2_4 = 0;
    P2_3 = 1;
    P2_2 = 0;
    break;
  case 7:
    P2_4 = 0;
    P2_3 = 0;
    P2_2 = 1;
    break;
  case 8:
    P2_4 = 0;
    P2_3 = 0;
    P2_2 = 0;
    break;
  }
  P0 = NexieTable[number];
  Delay(1);
  P0=0x00;
}