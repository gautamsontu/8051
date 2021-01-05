#include<reg51.h>
#include<UART.h>

void main()
{
	Config_UART();
	Set_UART_Data('A');
}
