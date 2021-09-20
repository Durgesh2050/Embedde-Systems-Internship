#include<regx51.h>
#define LCD P2
sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;

void lcd_init();
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);	
void lcd_str(unsigned char *);
void delay(int time);

void main()
{
  lcd_init();
	lcd_cmd(0x85);
	lcd_str("8051 Microcontroller");
	lcd_cmd(0xc5);
	lcd_str("Welcome to LCD Programming");
	while(1);
}

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
	rw=0;
	en=1;
	delay(5);
	en=0;
}
void lcd_data(unsigned char d)
{
 LCD=d;
	rs=1;  //send the data
	rw=0;
	en=1;
	delay(5);
	en=0;
}
void lcd_str(unsigned char *p)
{
 while(*p!='\0')
 {
	 lcd_data(*p);
    *p++;
 }
}

void delay(int time)
{
 int i, j;
	for(i=0;i<time;i++)
	for(j=0;j<1275;j++);
}
