#include "KEYSCAN.H"

bit key = 0;

void KeyScan() interrupt 0
{
	key = 1;
}
