#include "SEG.H"

code u8 seglib[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0xFF};
u8 segbuf[8] = {10,10,10,10,10,10,10,10};
u8 segcom = 0;

void seg()
{
	(segcom++ >= 7) ? segcom = 0 : segcom;
	
	P2 &= 0x1F;
	P0 = 0xFF;
	P2 |= 0xE0;
	
	P2 &= 0x1F;
	P0 = 1 << segcom;
	P2 |= 0xC0;
	
	P2 &= 0x1F;
	P0 = seglib[segbuf[segcom]];
	P2 |= 0xE0;
	P2 &= 0x1F;
}