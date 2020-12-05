void KeyScan()
{
	static unsigned char Keybuf;
	unsigned char temp;

	P3 = 0x0F;
	temp = P3 & 0x0F;
	P3 = 0xF0;
	temp |= P3 & 0xF0;
	
	temp = ~temp;
	
	if(Keytime >= 1000)Keytime = 1000;
	
	if(Keybuf ^ temp)
	{
		if(Keytime >= 80 && Keytime < 180)
		{
			if(key == temp && Kick == 0)
			{
				Kick = 2;	
				Keytime = !Keytime;
				return ;
			}
			Kick = 0;
			Keyboard(Keybuf);
		}
		Keybuf = temp;
		Keytime = !Keytime;
	}
	else if(Keytime >= 500 && (Keytime % 50) == 0 && Keytime < 1000)
	{
		Keyboard(temp);
		Kick = 3;
		if(Keytime >= 800)Keytime = 1000;
	}
	else if(Keytime >= 180 && Keytime < 500)  Kick = 1;
}
