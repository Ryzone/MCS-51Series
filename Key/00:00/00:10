#include "KEYSCAN.H"

sbit BTN = P3^2;
bit key = 0;

void KeyScan()	interrupt 0
{
	while(!BTN);
	key = 1;
}
