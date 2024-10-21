#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"

sbit LED_1 = P2^0;
sbit Key = P3^2 ;

void exti_0_init()
{
	EA = 1;
	IT0 = 1;
	EX0 = 1;
}

void main()
{
	exti_0_init();
	
	while(1)
	{
		
	}
}

void exti_0_wrok() interrupt 0
{
	Delay(20);
	if(Key == 0)
	{
		LED_1 = !LED_1;
	}
}