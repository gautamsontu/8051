#include<reg51.h>

sbit Sw1 = P1^0;
sbit Sw2 = P1^3;
sbit LED = P2^0;
sbit MOTOR = P2^1;

void main()
	{
		while(1)
			
				{
					if(Sw1 == 0)
						{
								LED = 1;
						}
					else 
						{
								LED = 0;
						}
					if(Sw2 == 0)
						{
								MOTOR = 1;
						}
					else 
						{
								MOTOR = 0;
						}
				}
	}