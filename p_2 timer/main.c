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

//�жϷ�����
void time0() interrupt 1
{
	static unsigned int i = 0;	//��̬����ʹ��iֵʼ�ձ�����һ���жϱ���
	
	TH0 = 0xFC;		//��Ҫ�����趨��ֵ
	TL0 = 0x66;
	
	i++;
	
	if(i == 1000)	//1s = 1000ms
	{
		i = 0;		//��ʱ��ɣ�����
		LED_1 = !LED_1;
	}
	
}