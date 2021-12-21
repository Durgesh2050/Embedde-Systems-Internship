#include<regx51.h>
sbit sw1=P1^0;
sbit sw2=P1^1;
sbit led1=P0^0;
sbit led2=P0^1;
sbit pin1=P2^0;
sbit pin2=P2^1;
sbit pin3=P2^2;
sbit pin4=P2^3;

void main()
{
	while(1)
	{
		if(sw1==0)
		{
			led1=0;
			led2=1;
		 pin1=0;
		 pin2=1;
		 pin3=0;
		 pin4=0;
	  }
		else if(sw2==0)
		{
		led1=1;
			led2=0;
		 pin1=0;
		 pin2=0;
		 pin3=0;
		 pin4=1;
		}
		else
		{
		led1=1;
			led2=1;
		 pin1=0;
		 pin2=0;
		 pin3=0;
		 pin4=0;
		}
	}	

}
