#include<reg51.h>
#include<delay.h>
#include<global.h>
#include<lcd.h>

#define LCD_Port P2
#define Set_LCD_Command_Mode()    Clr_Bit(P3, BIT5)  // For Command RS = 0
#define Set_LCD_Data_Mode()       Set_Bit(P3,BIT5)   // For Data RS = 1

static void Set_LCD_Clock()
{
	Clr_Bit(P3, BIT7);
	delay(1000);
	Set_Bit(P3, BIT7);
}

static void Write_LCD_Port(unsigned char value)
{
	LCD_Port = value;
}

void Set_LCD_Command(unsigned char Command)
{
	Write_LCD_Port(Command);    //Pass the command to LCD Port
	Set_LCD_Command_Mode();         // Set Command Mode
	Set_LCD_Clock();            // Enable
}

void Set_LCD_Data(unsigned char chdata)
{
	Write_LCD_Port(chdata);     //Pass the chdata to LCD Port
	Set_LCD_Data_Mode();        // Set Data Mode
	Set_LCD_Clock();            // Enable
}

void Set_LCD_String(unsigned char *str)
{
	while(*str != '\0')
	{
		Set_LCD_Data(*str);
		str++;
	}
}

void Initialize_LCD()
{
	Set_LCD_Command(0x38);
	Set_LCD_Command(0x0E);
	Set_LCD_Command(0x06);
}