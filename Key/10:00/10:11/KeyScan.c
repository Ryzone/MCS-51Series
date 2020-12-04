#include "KEYSCAN.H"

unsigned char key = 0,Kick = 0,Keybuf = 0;

void Keyboard(unsigned char keyval)
{
	key = keyval;
}
void KeyScan()
{
	static unsigned int Keytime;
	unsigned char Trg;

	P3 = 0x0F;
	Trg = P3 & 0x0F ^ 0x0F;
	P3 = 0xF0;
	Trg |= P3 & 0xF0 ^ 0xF0;
	
	if(Keybuf ^ Trg)
	{
		if(Keytime >= 1200)Kick = 2;
		else if(Keytime >= 80)Kick = 1;
		
		Keyboard(Keybuf);
		Keybuf = Trg;
		
		Keytime = 0;
	}
	else Keytime++;
}
