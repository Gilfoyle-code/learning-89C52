#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "LCD1602.h"
#include "MatrixKey.h"
#include "Timer0.h"

unsigned char sec = 55,min = 59,hour = 0;
unsigned char keyNum = 0;
unsigned char mode = 0;
unsigned char show_flag = 0;
unsigned char number = 0;

unsigned char step = 0;

unsigned char test = 0;

void main()
{

	Timer0Init();
	
	while(1)
	{
		if(mode == 0)
		{
			
			if(show_flag == 0)
			{
				LCD_Init();
				LCD_ShowString(1,1,"Clock:");	//�ϵ���ʾ��̬�ַ���
				LCD_ShowString(2,1,"  :  :");
				show_flag = 1;
			}
			
			LCD_ShowNum(2,1,hour,2);	//��ʾʱ����
			LCD_ShowNum(2,4,min,2);
			LCD_ShowNum(2,7,sec,2);
			mode = 0;
		}
		
		keyNum = Key();
		switch(keyNum)
		{
			case 1:
				LCD_Init();
				LCD_ShowString(1,1,"Set Clock:");	//�ϵ���ʾ��̬�ַ���
		}
		
	}
}


void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x18;			//���ö�ʱ��ֵ
	TH0 = 0xFC;			//���ö�ʱ��ֵ
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;
		sec++;
		if(sec>=60)
		{
			sec=0;		//60�뵽��Sec��0��Min����
			min++;
			if(min>=60)
			{
				min=0;	//60���ӵ���Min��0��Hour����
				hour++;
				if(hour>=24)
				{
					hour=0;	//24Сʱ����Hour��0
				}
			}
		}
	}
}