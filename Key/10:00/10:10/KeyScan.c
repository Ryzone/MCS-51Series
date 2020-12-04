#include "KEYSCAN.H"

unsigned char key = 0,Kick = 0;

void Keyboard(unsigned char keyval)
{
	key = keyval;
}
void KeyScan()
{
	static unsigned int keytime;
	unsigned char key_buf;
	
	P3 = 0x0F;
	
	if(P3 & 0x0F ^ 0x0F)keytime++;
	else keytime = 0;	
	
	if(keytime>=500)Kick = 2;
	else if(keytime>=80)
		{
			P3 = 0x0F;
			key_buf = P3 & 0x0F ^ 0x0F;
			P3 = 0xF0;
			key_buf |= P3 & 0xF0 ^ 0xF0;
			Keyboard(key_buf);
			Kick = 1;
		}
	else Kick = 0;
} 
