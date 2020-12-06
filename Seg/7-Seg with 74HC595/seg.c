#include "SEG.H"

code u8 seglib[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x00,0X6D,0x7E,0x37,0xF9};	//0-9¡¢Ãð¡¢SWNE
u8 segbuf[4]={0,3,1,8};
u8 segcom = 0;

sbit H_SCK = P3^4;
sbit H_SDA = P1^6;
sbit OE = P1^7;
sbit RCK = P1^5;

void HC595(u8 dat)
{
	u8 i;
	RCK = 0;
	for(i=0;i<8;i++)
	{
		H_SCK = 1;	   
		H_SDA = dat&0x80;
		H_SCK = 0;
		dat <<= 1;
		H_SCK = 1;	
	}
	RCK = 1;
}
void seg()
{
	P4 |= 0xF0;
	
	OE = 1;
	HC595(seglib[segbuf[segcom]]);
	OE = 0;

	P4 &= ~(1<<(7-segcom));
	if(++segcom>=4)segcom=0;
}
