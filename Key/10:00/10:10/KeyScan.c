#include "KEYSCAN.H"

unsigned char key = 0,Kick = 0;

void Keyboard(unsigned char keyval)
{
	key = keyval;
}
void KeyScan()
{
	static unsigned int keytime;
	unsigned char keybuf;
	
	P3 = 0x0F;
	
	if(P3 & 0x0F ^ 0x0F)keytime++;
	else keytime = 0;	
	
	if(keytime>=80)
	{
		if(keytime>=500)Kick = 2;
		else Kick = 1;
		
		P3 = 0x0F;
		keybuf = P3 & 0x0F ^ 0x0F;
		P3 = 0xF0;
		keybuf |= P3 & 0xF0 ^ 0xF0;
		
		Keyboard(keybuf);
	}
	else Kick = 0;
}
