//rotate 2 times
#include<regx51.h>

void delay(int time)
{
	int i,j;
	for(i=0;i<time;i++)
	for(j=0;j<1275;j++);
}
void main()
{
	int rotate=0;
 while(rotate<2)
 {
  P2=0x01;    //0000 0001
	delay(200);
	P2=0x02;    //0000 0010
	delay(200);
	P2=0x04;    //0000 0100
	delay(200);
	P2=0x08;    //0000 1000
	delay(200);
	 
	 rotate++;
 }
 while(1);
}
