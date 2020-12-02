#include "KEYSCAN.H"

unsigned char key = 0;

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
void Button(unsigned char keyval)
{
	switch(keyval)
	{
		case 0x01 : key = 1;break;
		case 0x02 : key = 2;break;
		case 0x04 : key = 3;break;
		case 0x08 : key = 4;break;
	}
}
void KeyScan()
{
	P3 = 0x0F;
	if(P3 & 0x0F)
	{
		Delay80ms();
		if(P3 & 0x0F)
        Button(P3 & 0x0F ^ 0x0F);
	}
}
