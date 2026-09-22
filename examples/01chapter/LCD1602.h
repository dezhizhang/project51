/*
 * :file description: 
 * :name: /project51/examples/01chapter/LCD1602.h
 * :author: 张德志
 * :date created: 2026-09-20 05:00:56
 * :last editor: 张德志
 * :date last edited: 2026-09-22 21:54:22
 */
/*
 * LCD1602.h — LCD1602 液晶显示模块对外接口
 */

#ifndef __LCD1602_H__
#define __LCD1602_H__

void LCD_Init(void);
void LCD_ShowChar(unsigned char Line, unsigned char Column, char Char);
void LCD_ShowString(unsigned char Line, unsigned char Column, char *String);
void LCD_ShowNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length);
void LCD_ShowSignedNum(unsigned char Line, unsigned char Column, int Number, unsigned char Length);
void LCD_ShowHexNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length);
void LCD_ShowBinNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length);

#endif /* __LCD1602_H__ */
