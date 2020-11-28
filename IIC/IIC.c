#include "IIC.h"

sbit SCL = P1^0;
sbit SDA = P1^1;

void IIC_Start()
{
	SDA = 1;
	SCL = 1;
	
	SDA = 0;
	SCL = 0;
}
void IIC_Stop()
{
	SCL = 0;
	SDA = 0;
	
	SCL = 1;
	SDA = 1;
}
void IIC_SendByte(u8 dat)
{
	u8 i;
	
	EA = 0;
	
	for(i=0;i<8;i++)
	{
		SDA = dat & 0x80;
		SCL = 1;
		
		dat <<= 1;
		SCL = 0;
	}
	
	EA = 1;
}
u8 IIC_ReadByte()
{
	u8 i,dat;
	
	EA = 0;
	
	SDA = 1;
	
	for(i=0;i<8;i++)
	{
		dat <<= 1;
		SCL = 1;
		
		dat |= SDA;
		SCL = 0;
	}
	
	EA = 1;
	
	return dat;
}
bit IIC_WaitAck()
{
	bit ACK;
	
	SDA = 1;
	
	SCL = 1;
	ACK = SDA;
	SCL = 0;
	
	return ACK;
}
void IIC_Ack()
{
	SDA = 0;
	SCL = 1;
	SCL = 0;
}
void IIC_NAck()
{
	SDA = 1;
	SCL = 1;
	SCL = 0;
}
void IIC_SingleByte_Write(u8 Dev_Addr,u8 OP_Addr,u8 dat)
{
	IIC_Start();
	
	IIC_SendByte(Dev_Addr&0xFE);
	IIC_WaitAck();
	
	IIC_SendByte(OP_Addr);
	IIC_WaitAck();
	
	IIC_SendByte(dat);
	IIC_WaitAck();
	
	IIC_Stop();
}
u8 IIC_SingleByte_Read(u8 Dev_Addr,u8 OP_Addr)
{
	u8 dat;
	
	IIC_Start();
	
	IIC_SendByte(Dev_Addr&0xFE);
	IIC_WaitAck();
	
	IIC_SendByte(OP_Addr);
	IIC_WaitAck();
	
	IIC_Start();
	
	IIC_SendByte(Dev_Addr|0x01);
	IIC_WaitAck();
	
	dat = IIC_ReadByte();
	IIC_NAck();
	
	IIC_Stop();
	
	return dat;
}
void IIC_Page_Write(u8 Dev_Addr,u8 OP_Addr,u8 *dats,u8 Bytes)
{
	u8 i;
	
	IIC_Start();
	
	IIC_SendByte(Dev_Addr&0xFE);
	IIC_WaitAck();
	
	IIC_SendByte(OP_Addr);
	IIC_WaitAck();

	for(i=0;i<Bytes;i++)
	{
		IIC_SendByte(dats[i]);
		IIC_WaitAck();
	}
	
	IIC_Stop();
}

void IIC_Page_Read(u8 Dev_Addr,u8 StartAddr,u8 *dats,u8 Bytes)
{
	u8 i;
	
	IIC_Start();
	
	IIC_SendByte(Dev_Addr&0xFE);
	IIC_WaitAck();
	
	IIC_SendByte(StartAddr);
	IIC_WaitAck();
	
	
	IIC_Start();
	
	IIC_SendByte(Dev_Addr|0x01);
	IIC_WaitAck();
	
	for(i=0;i<Bytes;i++)
	{
		dats[i] = IIC_ReadByte();
		IIC_Ack();
	}
	
	dats[i] = IIC_ReadByte();
	IIC_NAck();
	
	IIC_Stop();
}


