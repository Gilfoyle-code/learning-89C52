#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include <INTRINS.H>

unsigned char KeyNum,LEDMode;

void main()
{
	P2=0xFE;
	Timer0Init();
	while(1)
	{
		KeyNum=Key();		//��ȡ������������
		if(KeyNum)			//�����������
		{
			if(KeyNum==1)	//���K1��������
			{
				LEDMode++;	//ģʽ�л�
				if(LEDMode>=2)LEDMode=0;
			}
		}
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x18;		//���ö�ʱ��ֵ
	TH0 = 0xFC;		//���ö�ʱ��ֵ
	T0Count++;		//T0Count�ƴΣ����ж�Ƶ�ʽ��з�Ƶ
	if(T0Count>=200)//��Ƶ500�Σ�500ms
	{
		T0Count=0;
		if(LEDMode==0)			//ģʽ�ж�
			P2=_crol_(P2,1);	//LED��� //ѭ������
		if(LEDMode==1)
			P2=_cror_(P2,1);	//ѭ������
	}
}
