#include<regx51.h>
#include"lcd.h"
sbit c1=P1^0;
sbit c2=P1^1;
sbit c3=P1^2;
sbit r1=P1^3;
sbit r2=P1^4;
sbit r3=P1^5;
sbit r4=P1^6;



void main()
{
	unsigned char i, a[4][3]={'1','2','3',
												    '4','5','6',
											      '7','8','9',
		                        '*','0','#'};
	
  lcd_init();
	lcd_cmd(0x01);
	lcd_cmd(0x080);
	lcd_str("Keypad programming");
	lcd_cmd(0xc0);
	 
  for(i=0;i<10;i++)
{
	 P1=0x07;  //// 0000 0111
	while(c1 && c2 && c3);  //stay here until press any key
	
	r1=0;
	r2=r3=r4=1;
	if(c1==0)
	{
	 while(c1==0);
		lcd_data(a[0][0]);
	}
	if(c2==0)
	{
	 while(c2==0);
		lcd_data(a[0][1]);
	}
	if(c3==0)
	{
	 while(c3==0);
		lcd_data(a[0][2]);
	}
	r2=0;
	r1=r3=r4=1;
	if(c1==0)
	{
	 while(c1==0);
		lcd_data(a[1][0]);
	}
	if(c2==0)
	{
	 while(c2==0);
		lcd_data(a[1][1]);
	}
	if(c3==0)
	{
	 while(c3==0);
		lcd_data(a[1][2]);
	}
	r3=0;
	r1=r2=r4=1;
	if(c1==0)
	{
	 while(c1==0);
		lcd_data(a[2][0]);
	}
	if(c2==0)
	{
	 while(c2==0);
		lcd_data(a[2][1]);
	}
	if(c3==0)
	{
	 while(c3==0);
		lcd_data(a[2][2]);
	}
	r4=0;
	r2=r3=r1=1;
	if(c1==0)
	{
	 while(c1==0);
		lcd_data(a[3][0]);
	}
	if(c2==0)
	{
	 while(c2==0);
		lcd_data(a[3][1]);
	}
	if(c3==0)
	{
	 while(c3==0);
		lcd_data(a[3][2]);
	}
	
}
while(1);
	
}
////header file

#define LCD P2
sbit rs=P3^0;
sbit en=P3^1;


void lcd_init();
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);	
void lcd_str(unsigned char *);
void delay(int time);

void lcd_init()
{
  lcd_cmd(0x38);  //enable the 5x7 dot matrix
	delay(5);
	lcd_cmd(0x0f); //display on cursor blinking
	delay(5);
	lcd_cmd(0x01);  //clear screen
	delay(5);
	lcd_cmd(0x80);  //lcd first row first column
	delay(5);
	
}
void lcd_cmd(unsigned char c)
{
 LCD=c;
	rs=0;  //send the command
	en=1;
	delay(5);
	en=0;
}
void lcd_data(unsigned char d)
{
 LCD=d;
	rs=1;  //send the data
	en=1;
	delay(5);
	en=0;
}
void lcd_str(unsigned char *p)
{
 while(*p!='\0')
 {
	 lcd_data(*p++);
 }
}

void delay(int time)
{
 int i, j;
	for(i=0;i<time;i++)
	for(j=0;j<1275;j++);
}
