#include <STC15F2K60S2.H>

#include "KEYSCAN.H"

void All_Init()
{
	P32 = 1;
	IT0 = 1;
	EX0 = 1;
	
	EA = 1;
}

void main()
{
    All_Init();
	while(1);
}
