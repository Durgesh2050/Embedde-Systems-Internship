//unipolar wave mode
#include<regx51.h>

void delay(int time)
{
	int i,j;
	for(i=0;i<time;i++)
	for(j=0;j<1275;j++);
}
void main()
{
 while(1)
 {
  P2=0x01;    //0000 0001
	delay(200);
	P2=0x02;    //0000 0010
	delay(200);
	P2=0x04;    //0000 0100
	delay(200);
	P2=0x08;    //0000 1000
	delay(200);
	 
 }
}


