#include <REGX52.H>
#include <NixieTube.h>
#include <delay.h>

void main()
{
	
	unsigned char location = 8;
    unsigned char number = 0;
	unsigned char flag = 0;
	
    NixieOutputs out;
	
	
	while(1)
	{
		location -= flag;		
		number += flag;
		out = nixieTube(location, number);
	
		P2_4 = out.P2_4;
		P2_3 = out.P2_3;
		P2_2 = out.P2_2;
		
		P0 = out.P0;
		
		if(flag >= 0 && flag < 7)
		{
			location = 8;
			number = 0;
			flag++;
		}
		else
		{
			location = 8;
			number = 0;
			flag = 0;
		}
		delayms(1000);
		
	}
	
}