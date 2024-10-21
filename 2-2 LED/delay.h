#include <REGX52.H>
#include <INTRINS.H>

void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void Delay100ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 180;
	j = 73;
	do
	{
		while (--j);
	} while (--i);
}

void Delay_xms(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms--)
	{	
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	
	}	
	
}
