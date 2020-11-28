#ifndef _IIC_H
#define _IIC_H

#include "STC15F2K60S2.h"


#define u8 unsigned char
#define u16 unsigned int

extern void IIC_SingleByte_Write(u8 Dev_Addr,u8 OP_Addr,u8 dat);
extern u8 IIC_SingleByte_Read(u8 Dev_Addr,u8 OP_Addr);

extern void IIC_Page_Write(u8 Dev_Addr,u8 OP_Addr,u8 *dats,u8 Bytes);
extern void IIC_Page_Read(u8 Dev_Addr,u8 OP_Addr,u8 *dats,u8 Bytes);

#endif
