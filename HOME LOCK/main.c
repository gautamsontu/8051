#include<reg51.h>
#include<delay.h>
#include<global.h>
#include<mkeys.h>
#include<lcd.h>

unsigned char Password[4]="1234";
// Keypad
void main()
{
	int i;
	unsigned char pass[4];
	unsigned char raw_value=0;
	Initialize_LCD();
	Config_mkeys();
	
		Set_LCD_Command(0x38); /* Initialization of 16X2 LCD in 8bit mode */
		delay(100);
		Set_LCD_Command(0x0F);  /* LCD ON, Cursor ON, Cursor blinking ON */
		delay(100);
		Set_LCD_Command(0x0E);  /* Display ON ,Cursor blinking OFF */
		delay(100);
		Set_LCD_Command(0x80);	/* Force cursor to the beginning of  1st line */
		delay(100);
		Set_LCD_String("Enter Password:");
	
	while(1)
	{
		for(i=0;i<4;i++)
		{
			while(!(pass[i]= Get_Key()));
			Set_LCD_Command(0xC0+i);
			Set_LCD_Data(*pass);			
		}
	}
}


