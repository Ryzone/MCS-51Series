#include "KEYSCAN.H"

sbit BTN = P3^2;
bit key = 0;

void Delay80ms()
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
void KeyScan() interrupt 0
{
	Delay80ms();
	if(!BTN)key = 1;
}
