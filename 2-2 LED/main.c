#include <REGX52.H>
#include <delay.h>

void main()
{
	int i = 0;
	for(; i < 8; i++)
	{
		P2 = ~(0x01 << i);
		Delay_xms(100);
	}
		
}