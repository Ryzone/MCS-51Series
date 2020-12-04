#include "KEYSCAN.H"

unsigned char key = 0,Kick = 0,Keybuf = 0;
unsigned int Keytime;


void Keyboard(unsigned char keyval)
{
	key = keyval;
}
void KeyScan()
{
	unsigned char scan;

	P3 = 0x0F;
	scan = P3 & 0x0F ^ 0x0F;
	P3 = 0xF0;
	scan |= P3 & 0xF0 ^ 0xF0;
	
	if(Keybuf ^ scan)
	{
		if(Keytime >= 1200)Kick = 2;
		else if(Keytime >= 80)Kick = 1;
		
		Keyboard(Keybuf);
		Keybuf = scan;
		
		Keytime = 0;
	}
	else Keytime++;
}
