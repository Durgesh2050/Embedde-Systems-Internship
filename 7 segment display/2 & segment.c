//up to 22 numbers
#include<regx51.h>

void delay(int t)
{
 int i,j;
	for(i=0;i<t;i++)
	for(j=0;j<1275;j++);
}

void main()
{
	int i,j,a[10]={0X3F, 0X06, 0X5B, 0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
  for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			P2=a[i];
			P3=a[j];
			delay(100);
			if(i==1 && j==2)
			while(1);        //stay here
		}
  }
	
}
