#include<reg51.h>
#include<global.h>
#include<lcd.h>

void main()
{
	Initialize_LCD();
	while(1)
	{
		/*Set_LCD_Command(0x80);
		Set_LCD_Data('A');
		Set_LCD_Command(0xC0);
		Set_LCD_Data('B'); */
		Set_LCD_Command(0x80);
		Set_LCD_String("hi im Gautam!");
		Set_LCD_Command(0xC0);
		Set_LCD_String("im 19 yo!");
	} 
}
