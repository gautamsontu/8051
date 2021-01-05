#include<reg51.h>
#include<global.h>
#include<lcd.h>
#include<mkeys.h>

void main()
{
	unsigned char raw_value=0;
	Initialize_LCD();
	Config_mkeys();
	
	while(1)
	{
		Set_LCD_Command(0x80);
		Set_LCD_String("My Key Values");
		raw_value=Get_Key();
		if(raw_value)
		{
			Set_LCD_Command(0xC0);
			Set_LCD_Data(raw_value);
		}
	}
}