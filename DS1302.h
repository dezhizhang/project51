/*
 * :file description: 
 * :name: /project51/DS1302.H
 * :author: 张德志
 * :date created: 2026-09-22 04:50:32
 * :last editor: 张德志
 * :date last edited: 2026-09-22 05:33:55
 */
#ifndef __DS1302_H__
#define __DS1302_H__



void DS1302_Init();
void DS1302_WriteByte(unsigned char Command, unsigned char Data);
unsigned char DS1302_ReadByte(unsigned char Command);

#endif