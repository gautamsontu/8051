#include<reg51.h>
#include<global.h>
#include<mkeys.h>

#define mkeys P1

#define Sense_Column1()  Is_Bit_Clr(P1,BIT4)
#define Sense_Column2()  Is_Bit_Clr(P1,BIT5)
#define Sense_Column3()  Is_Bit_Clr(P1,BIT6)
#define Sense_Column4()  Is_Bit_Clr(P1,BIT7)

void Active_Row1()
{
	Clr_Bit(P1,BIT0);
	Set_Bit(P1,BIT1);
	Set_Bit(P1,BIT2);
	Set_Bit(P1,BIT3);
}
void Active_Row2()
{
	Set_Bit(P1,BIT0);
	Clr_Bit(P1,BIT1);
	Set_Bit(P1,BIT2);
	Set_Bit(P1,BIT3);
}
void Active_Row3()
{
	Set_Bit(P1,BIT0);
	Set_Bit(P1,BIT1);
	Clr_Bit(P1,BIT2);
	Set_Bit(P1,BIT3);
}
void Active_Row4()
{
	Set_Bit(P1,BIT0);
	Set_Bit(P1,BIT1);
	Set_Bit(P1,BIT2);
	Clr_Bit(P1,BIT3);
}
void Config_mkeys(void)
{
	mkeys=0xff;
}
unsigned char Key_Buf[16]="789%456*123-0=+";
unsigned char Get_Key()
{
	unsigned char Key=0;
	 
	Active_Row1();
	if(Sense_Column1())
	{
		while(Sense_Column1());
		Key=Key_Buf[0];
	}
	else if(Sense_Column2())
	{
		while(Sense_Column2());
		Key=Key_Buf[1];
	}
	else if(Sense_Column3())
	{
		while(Sense_Column3());
		Key=Key_Buf[2];
	}
	else if(Sense_Column4())
	{
		while(Sense_Column4());
		Key=Key_Buf[3];
	}
	else
		{
				Active_Row2();
		if(Sense_Column1())
		{
			while(Sense_Column1());
			Key=Key_Buf[4];
		}
		else if(Sense_Column2())
		{
			while(Sense_Column2());
			Key=Key_Buf[5];
		}
		else if(Sense_Column3())
		{
			while(Sense_Column3());
			Key=Key_Buf[6];
		}
		else if(Sense_Column4())
		{
			while(Sense_Column4());
			Key=Key_Buf[7];
		}
			else
			{
					Active_Row3();
			if(Sense_Column1())
			{
				while(Sense_Column1());
				Key=Key_Buf[8];
			}
			else if(Sense_Column2())
			{
				while(Sense_Column2());
				Key=Key_Buf[9];
			}
			else if(Sense_Column3())
			{
				while(Sense_Column3());
				Key=Key_Buf[10];
			}
			else if(Sense_Column4())
			{
				while(Sense_Column4());
				Key=Key_Buf[11];
			}
				else
						{
						Active_Row4();
				if(Sense_Column1())
				{
					while(Sense_Column1());
					Key=Key_Buf[12];
				}
				else if(Sense_Column2())
				{
					while(Sense_Column2());
					Key=Key_Buf[13];
				}
				else if(Sense_Column3())
				{
					while(Sense_Column3());
					Key=Key_Buf[14];
				}
				else if(Sense_Column4())
				{
					while(Sense_Column4());
					Key=Key_Buf[15];
				}
			}
		}
	}
		return Key;
}