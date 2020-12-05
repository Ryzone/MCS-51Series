#include "KEYSCAN.H"

unsigned char key = 0,Kick = 0;
unsigned int Keytime;

void KeyScan()
{
	static unsigned char Keybuf,Kickbuf,state;
	unsigned char temp;

	P3 = 0x0F;
	temp = P3 & 0x0F;
	P3 = 0xF0;
	temp |= P3 & 0xF0;
	
	temp = ~temp;
	
	(Keytime >= 1000) ? Keytime = 1000 : 0;
	
	if(Keybuf ^ temp)
	{
		if(Keytime >= 20 && Keytime < 250)
		{
			(key == temp && temp ^ state) ? Kickbuf++ : 0;
			key = Keybuf;
		}
		(!Kickbuf) ? Kickbuf = 1 : 0;
		Keybuf = temp;
		Keytime = !Keytime;
	}
	else if(Keytime >= 500 && (Keytime % 50) == 0 && Keytime < 1000)
	{
		key = state = temp;
		Kick = 9;
		(Keytime >= 800) ? Keytime = 1000 : 0;
	}
	else if(Keytime >= 250 && Keytime < 500)
	{
		if(Kickbuf)Kick = Kickbuf;
		Kickbuf = 0;
	}
}
