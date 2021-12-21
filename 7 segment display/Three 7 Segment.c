#include<regx51.h>
sbit seg0=P3^0;
sbit seg1=P3^1;
sbit seg2=P3^2;
void delay(int t)
{
 int i,j;
	for(i=0;i<t;i++)
	for(j=0;j<500;j++);
}

void main()
{
	int i,j,k,a[10]={0X3F, 0X06, 0X5B, 0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
  for(i=0;i<10;i++)
	{
		seg0=1;  
		seg1=1;  
		seg2=0;
		P2=a[i];
		delay(1);
		for(j=0;j<10;j++)
		{
			seg0=1;  
		  seg1=0;    
			seg2=1;
			P2=a[j];
			delay(1);
			for(k=0;k<10;k++)
			{
			seg0=0;  
		  seg1=1;    
			seg2=1;
			P2=a[k];
			delay(1);
			}
		}
  }
	
}
