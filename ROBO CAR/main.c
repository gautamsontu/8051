#include<reg51.h>
#include<global.h>
#include<car.h>

sbit SwF = P1^0;
sbit SwB = P1^1;
sbit SwL = P1^2;
sbit SwR = P1^3;
sbit SwS = P1^4;
	
void main()
{
	Stop();
	while(1)
	{
	if(SwF == 0)
	{
		Forward();
	}
	else if (SwB == 0)
	{
		Backward();
	}
	else if (SwR == 0)
	{
		Right();
	}
	else if (SwL == 0)
	{
		Left();
	}
	else
	{
		Stop();
	}	
}
}