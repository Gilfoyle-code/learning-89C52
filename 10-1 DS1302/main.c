#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"

unsigned char Second, Minute = 0;

void main()
{
	LCD_Init();
	DS1302_Init();
	DS1302_WriteByte(0x8e,0x00);//�ر�д�뱣��
	LCD_ShowString(1,1,"  -  -  ");//��̬�ַ���ʼ����ʾ
	LCD_ShowString(2,1,"  :  :  ");
	DS1302_SetTime();//����ʱ��
	while(1)
	{
		DS1302_ReadTime();//��ȡʱ��
		LCD_ShowNum(1,1,DS1302_Time[0],2);//��ʾ��
		LCD_ShowNum(1,4,DS1302_Time[1],2);//��ʾ��
		LCD_ShowNum(1,7,DS1302_Time[2],2);//��ʾ��
		LCD_ShowNum(2,1,DS1302_Time[3],2);//��ʾʱ
		LCD_ShowNum(2,4,DS1302_Time[4],2);//��ʾ��
		LCD_ShowNum(2,7,DS1302_Time[5],2);//��ʾ��
	}
}