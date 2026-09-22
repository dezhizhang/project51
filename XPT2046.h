/*
 * :file description:
 * :name: /project51/XPT2046.h
 * :author: 张德志
 * :date created: 2026-09-23 05:41:58
 * :last editor: 张德志
 * :date last edited: 2026-09-23 06:15:41
 */
#ifndef __XPT2046_H__
#define __XPT2046_H__

#define XPT2046_XP 0x9C
#define XPT2046_YP 0xDC
#define XPT2046_YP 0xDC
#define XPT2046_VBAT 0xAC
#define XPT2046_AUX 0xEC

unsigned int XPT2046_ReadAD(unsigned char Command);

#endif /* __XPT2046_H__ */