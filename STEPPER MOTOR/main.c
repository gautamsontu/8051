#include<reg51.h>
#include<delay.h>
#define Stepper P2

sbit SwC = P1^1;
sbit SwA = P1^2;

void Stop()
{
	Stepper = 0x00;
}
void Clockwise()
{
	Stepper = 0x01;
	delay(200);
	Stepper = 0x02;
	delay(200);
	Stepper = 0x04;
	delay(200);
	Stepper = 0x08;
	delay(200);
}
void Anticlockwise()
{
	Stepper = 0x08;
	delay(200);
	Stepper = 0x04;
	delay(200);
	Stepper = 0x02;
	delay(200);
	Stepper = 0x01;
	delay(200);
}
void main()
{
	while(1)
	{
		Stop();
		if(SwC == 0)
		{
		Clockwise();
		delay(100);
		}
		else if (SwA == 0)
		{
		Anticlockwise();
		delay(100);
		}
	}
}