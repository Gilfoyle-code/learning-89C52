#include <REGX52.H>
#include <LCD1602.h>
#include "Delay.h"

int Result = 0;

void main()
{
	LCD_Init();
	
	LCD_ShowString(1,1,"Hello World");
	
	while(1)
	{
		Result++;
		LCD_ShowNum(2, 1, Result, 3);
		Delayms(1000);
	}
	
}