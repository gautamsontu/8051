#include<reg51.h>
#include<UART.h>

unsigned char a =0;
					
sbit LED = P2^0;
sbit M1 = P2^1;
sbit M2 = P2^2;
sbit BULB = P2^3;

void main()
{
	LED = 0;
	M1 = 0;
	M2 = 0;
	BULB = 0;
	Config_UART();
	Set_UART_String("PC Control ");
	while(1)
	{
		a = Get_UART_data();
		if(a)
		{
			Set_UART_Data(a);
			switch(a)
			{
				case 'L': LED = 1; //Set_BIT(P2,BIT0)
					        break;
				case 'l': LED = 0;
					        break;
				case 'M': M1 = 1;
					        break;
				case 'm': M1 = 0;
					        break;
				case 'B': BULB = 1;
					        break;
				case 'b': BULB = 0;
					        break	;		
			}				
		}
	}
}