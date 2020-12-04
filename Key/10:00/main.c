#include <STC15F2K60S2.H>

#include "KEYSCAN.H"

void main()
{
  All_Init();
	while(1);
}
void Timer0_isr() interrupt 1
{
	KeyScan();
}
