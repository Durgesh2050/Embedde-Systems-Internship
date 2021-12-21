//two motors
#include<regx51.h>
sbit pin1=P2^0;
sbit pin2=P2^1;
sbit pin3=P2^2;
sbit pin4=P2^3;

void main()
{
	 pin1=0;
	 pin2=1;
	 pin3=0;
	 pin4=1;
	while(1);

}
