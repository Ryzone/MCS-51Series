#include "KEYSCAN.H"

unsigned char key = 0;

void Delay80ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 4;
	j = 93;
	k = 155;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
void Keyboard(unsigned char keyval)
{
	key = keyval;
}
void KeyScan()
{
	unsigned char key_buf;
	P3 = 0x0F;
	if(P3 & 0x0F ^ 0x0F)
	{
		Delay80ms();
		if(P3 & 0x0F ^ 0x0F)
		{
			key_buf = P3 & 0x0F ^ 0x0F;
			P3 = 0xF0;
			key_buf |= P3 & 0xF0 ^ 0xF0;
			Keyboard(key_buf);
		}
	}
}    
