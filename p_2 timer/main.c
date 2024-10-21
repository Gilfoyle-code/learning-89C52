#include <REGX52.H>

sbit LED_1 = P2^0;

void time0_Init(void)
{
	TMOD |= 0x01;
	TH0 = 0xFC;
	TL0 = 0x66;
	ET0 = 1;
	EA = 1;
	TR0 = 1;
}

void main()
{
	time0_Init();
	
	while(1)
	{
		
	}
}

//中断服务函数
void time0() interrupt 1
{
	static unsigned int i = 0;	//静态变量使得i值始终保持上一次中断变量
	
	TH0 = 0xFC;		//需要重新设定初值
	TL0 = 0x66;
	
	i++;
	
	if(i == 1000)	//1s = 1000ms
	{
		i = 0;		//定时完成，归零
		LED_1 = !LED_1;
	}
	
}