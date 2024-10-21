#include <REGX52.H>
#include <delay.h>

void main()
{
	unsigned char flag = '0';
	while(1)
	{
		if(P3_1 == 0)
		{
			P2_1 = 0;
		}
		else
		{
			P2_1 = 1;
		}
		
		//¿¥ªÿ≈‹¬Ìµ∆
		if(P3_0 == 0)
		{
			if(flag == '0')
			{
				//while(P3_0 == 0)
				//{
					int i = 0;
					for(; i < 8; i++)
					{
						P2 = ~(0x01 << i);
						Delayms(100);
						if(P3_0 != 0)
						{
							break;
						}
					}
					
				//}
					flag = '1';
			}
			if(flag == '1' && P3_0 == 0)
			{
					int i = 6;
					for(; i > 0; i--)
					{
						P2 = ~(0x01 << i);
						Delayms(100);
					}
					
					flag = '0';
			}
			
		}
		else
		{
			P2 = ~0;
		}
	}
}