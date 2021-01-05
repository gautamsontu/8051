#include<reg51.h>
#include<UART.h>

Config_UART()
{
	TMOD|= 0x20;    // Timer1 Mode 2
	TH1 = 0xFD;     // Baudrate 9600
	SCON = 0x50;    // 8bit dat + 1 stopbit + 1 startbit
	TR1 = 1;        // Start Trimer 1
}

void Set_UART_Data(unsigned char dat)
{
	SBUF = dat;
	while(TI == 0);  // Wait fot dat transmit
	TI = 0;          // Ready to transmit next dat again 
}

unsigned char Get_UART_data()
{
	unsigned char rawdata = 0;
	while(RI == 1)
	{
		rawdata = SBUF;  // pass the dat into variablre
		RI = 0;   // ready to receive next dat again 
  }
	return rawdata;
}

void Set_UART_String(unsigned char *str)
{
	while(*str != '\0')
		Set_UART_Data();
		str++;
}	