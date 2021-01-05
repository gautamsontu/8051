#include<reg51.h>
#include<delay.h>

#define Stepper P2

sbit SwDoor = P1^0;
sbit SwLight = P1^1;
sbit SwFan = P1^2;
sbit SwOff = P1^3;

sbit LED = P3^0;
sbit Motor1 = P3^1;
sbit Motor2 = P3^3;

void DoorOpen()
{
	Stepper = 0x01;
	delay(200);
	Stepper = 0x02;
}
void DoorClose()
{
	Stepper = 0x02;
	delay(200);
	Stepper = 0x01;
}
void Close()
{
	Stepper = 0x00;
}
void main()
	{
		Close();
		LED = 0;
		Motor1 = 0;
		Motor2 = 0;
		
		if(SwDoor == 0)
			{
				DoorOpen();
				delay(1000);
				DoorClose();
				delay(1000);
				Close();
			}		
		else if (SwLight == 0)
			{
				LED = 1;
			}
		else if (SwFan == 0)
			{
				Motor1 = 1;
				Motor2 = 0;
			}
		else if (SwOff == 0)
			{
				LED = 0;
				Motor1 = 0;
				Motor2 = 0;
			}		
	}