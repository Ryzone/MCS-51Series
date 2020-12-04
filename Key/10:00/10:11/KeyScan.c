#include "KEYSCAN.H"

unsigned char key = 0,Kick = 0;

void Keyboard(unsigned char keyval)
{
	key = keyval;
}
void KeyScan()
{
	static unsigned char Keybuf;
	static unsigned int Keytime;
	unsigned char temp;

	P3 = 0x0F;
	temp = P3 & 0x0F ^ 0x0F;
	P3 = 0xF0;
	temp |= P3 & 0xF0 ^ 0xF0;
	
	if(Keybuf ^ temp)
	{
		if(Keytime >= 80)
		{
			if(Keytime >= 1200)Kick = 2;
			else Kick = 1;
			Keyboard(Keybuf);
		}
		
		Keybuf = temp;
		
		Keytime = 0;
	}
	else Keytime++;
}
