#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"

unsigned char Second, Minute = 0;

void main()
{
	LCD_Init();
	DS1302_Init();
	DS1302_WriteByte(0x8e,0x00);//关闭写入保护
	LCD_ShowString(1,1,"RTC");
	
	DS1302_WriteByte(0x80, 0x00);
	
	while(1)
	{
		Second = DS1302_ReadByte(0x81);
		Minute = DS1302_ReadByte(0x83);
		LCD_ShowNum(2,1,Minute/16*10 + Minute%16,2);
		LCD_ShowNum(2,3,Second/16*10 + Second%16,2);
	}
}