实现功能

#### 存在问题：
由于硬件电路限制，无法实现矩阵组合键，仅可实现特殊组合键

#### 尝试解决：

1. 使用逐行逐列扫描，可提升稳定性，但无法解决多组合键问题
2. 使用短整型(16bit)变量存储对应按键状态，8位将导致不同组合键有相同键值，产生误判
3. 在反转电平后添加其他不相关语句，如(P0 = 0;），猜测产生一定时延，但不知道为什么空语句不行
4. 在硬件上添加二极管，单向导通，避免产生幽灵按键，读取误判

#### 计划修改

1. 规范化变量名
2. 添加间值宏定义

<details>
  <summary> 注释重修版 </summary>

```
#include "KEYSCAN.H"

unsigned char key = 0,Kick = 0;		//Key value,Key click
unsigned int Keytime;

void KeyScan()
{
	static unsigned char Keybuf,State,Kickbuf;
	unsigned char temp;

	P3 = 0x0F;P0 = 0;
	temp = P3 & 0x0F ^ 0x0F;
	P3 = 0xF0;P0 = 0;
	temp |= P3 & 0xF0 ^ 0xF0;
	
	(Keytime >= 1000) ? Keytime = 1000 : 0;
	
	if(Keybuf ^ temp)
	{
		if(Keytime >= 20 && Keytime < 250)
		{
			(key == temp && temp ^ State) ? Kickbuf++ : 0;
			key = Keybuf;
		}
		(!Kickbuf) ? Kickbuf = 1 : 0;
		Keybuf = temp;
		Keytime = !Keytime;
	}
	else 
  	{
    		if(Keytime >= 500 && (Keytime % 50) == 0 && Keytime < 1000)
		{
			key = State = temp;
			Kick = 255;
			Kickbuf = 0;
			(Keytime >= 800) ? Keytime = 1000 : 0;
		}
		else 
   		{
			if(Keytime >= 250 && Keytime < 500)
			{
		  		if(Kickbuf)Kick = Kickbuf;
		  		Kickbuf = 0;
			}
		}
   	}
}
```
