#include <REGX52.H>
#include "NixieTube.h"

//0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F,Пе
unsigned char NIXIETABLE[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 
	0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x00};

NixieOutputs  nixieTube(unsigned char location, number)
{
	NixieOutputs out;

	
	switch(location)
	{
		case 8: out.P2_4 = 1; out.P2_3 = 1; out.P2_2 = 1;	break;
		case 7: out.P2_4 = 1; out.P2_3 = 1; out.P2_2 = 0;	break;
		case 6: out.P2_4 = 1; out.P2_3 = 0; out.P2_2 = 1;	break;
		case 5: out.P2_4 = 1; out.P2_3 = 0; out.P2_2 = 0;	break;
		case 4: out.P2_4 = 0; out.P2_3 = 1; out.P2_2 = 1;	break;
		case 3: out.P2_4 = 0; out.P2_3 = 1; out.P2_2 = 0;	break;
		case 2: out.P2_4 = 0; out.P2_3 = 0; out.P2_2 = 1;	break;
		case 1: out.P2_4 = 0; out.P2_3 = 0; out.P2_2 = 0;	break;
		default: break;
	}
	
	out.P0 = NIXIETABLE[number];
	
	return out;
}