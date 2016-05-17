/*
 * _5LED_with_range.c
 *
 * Created: 17/04/2015 10:23:35 AM
 *  Author: Toshiba
 */ 

  

#include <avr/io.h>
#include <util/delay.h>
#define rs PD0
#define en PD1

void lcd_init();
void command(unsigned char a);
void data(unsigned char a);
void command_shift(unsigned char b);
void data_shift(unsigned char b);

int main(void)
{
	
	DDRD=0xff;		// initialize data port(D4 to D7 as o/p pins)... any change in the port will require change of port name in place of PORTD in command and data function defination as well
	DDRB=0xff;
	int a,b;
	int x,y,z;
//	int adc0,adc1;
	lcd_init();
	while(1)
	{
// 		ADMUX=0x45;
// 		adc0=ADC;

		// channel 0 i.e. ADC0
		for(int i=0;i<3;i++)
		{
			if(i==0)
 			{
				ADMUX=0x40;					// selection of channel 0 i.e. ADC0
				command(0x80);				// position at with its value will be shown on LCD
				ADCSRA|=(1<<ADEN)|(1<<ADSC)|(1<<ADFR)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
				while((ADCSRA & (1<<ADIF))==0);		 //it waits until condi. satisfies i.e. remains in while loop until conversion completes
				// while(~(ADCSRA & (1<<ADIF))); can also be written as ADIF will be 0 untill conversion continues and and ADIF becomes 1 when conversion completes and hence it terminates from the loop

				a=ADC;
				a=a*.490;
				x=a;
				
				if(a>=0)
				data('+');
				else
				{
					data('-');
					a=a*(-1);
				}
				
				b=(a/100)+48;
				data(b);
				a=a%100;							// we devied by 2 as LM35 gives double value of the actual value i.e.
				b=(a/10)+48;
				data(b);
				b=(a%10)+48;
				data(b);
			}
			else if(i==1)
			{
				ADMUX=0x41;					// selection of channel 1 i.e. ADC1
				command(0x86);				// position at with its value will be shown on LCD
				ADCSRA|=(1<<ADEN)|(1<<ADSC)|(1<<ADFR)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
				while((ADCSRA & (1<<ADIF))==0);		 //it waits until condi. satisfies i.e. remains in while loop until conversion completes
				// while(~(ADCSRA & (1<<ADIF))); can also be written as ADIF will be 0 untill conversion continues and and ADIF becomes 1 when conversion completes and hence it terminates from the loop

				a=ADC;
				a=a*.490;
				y=a;
				
				if(a>=0)
				data('+');
				else
				{
					data('-');
					a=a*(-1);
				}
				
				b=(a/100)+48;
				data(b);
				a=a%100;							// we devied by 2 as LM35 gives double value of the actual value i.e.
				b=(a/10)+48;
				data(b);
				b=(a%10)+48;
				data(b);
			}
			else
			{
				ADMUX=0x42;					// selection of channel 2 i.e. ADC2
				command(0x8c);				// position at with its value will be shown on LCD
				ADCSRA|=(1<<ADEN)|(1<<ADSC)|(1<<ADFR)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
				while((ADCSRA & (1<<ADIF))==0);		 //it waits until condi. satisfies i.e. remains in while loop until conversion completes
				// while(~(ADCSRA & (1<<ADIF))); can also be written as ADIF will be 0 untill conversion continues and and ADIF becomes 1 when conversion completes and hence it terminates from the loop

				
				a=ADC;
				a=a*.490;
				z=a;
				
				if(a>=0)
				data('+');
				else
				{
					data('-');
					a=a*(-1);
				}
				
				b=(a/100)+48;
				data(b);
				a=a%100;							// we devied by 2 as LM35 gives double value of the actual value i.e.
				b=(a/10)+48;
				data(b);
				b=(a%10)+48;
				data(b);
 			}
// 			ADCSRA|=(1<<ADEN)|(1<<ADSC)|(1<<ADFR)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
// 			while((ADCSRA & (1<<ADIF))==0);		 //it waits until condi. satisfies i.e. remains in while loop until conversion completes
// 			// while(~(ADCSRA & (1<<ADIF))); can also be written as ADIF will be 0 untill conversion continues and and ADIF becomes 1 when conversion completes and hence it terminates from the loop

// 			adc1=ADC;
// 			a=adc1-adc0;
			
					
			if(x>20 && x<31 && y>20 && y<31 && z>20 && z<31)
			{
				PORTB=0x01;
			}
			
			else if(x>45 && x<56 && y>45 && y<56 && z>45 && z<56)
			{
				PORTB=0x02;
			}
			else if(x>70 && x<81 && y>70 && y<81 && z>70 && z<81)
			{
				PORTB=0x04;
			}
			else if(x>95 && x<106 && y>95 && y<106 && z>95 && z<106)
			{
				PORTB=0x08;
			}
			else if(x>120 && x<131 && y>120 && y<131 && z>120 && z<131)
			{
				PORTB=0x10;
			}
			else
			{
				PORTB=0x00;
			}
		}
	}
}


// func declaration
void lcd_init()							// to initialize LCD
{
	command(0x02);						//4bit LCD select
	command(0x28);						//LCD init basic command(4bit LCD, 2 lines, 5X7
	command(0x06);						//LCD init basic command
	command(0x0c);						//to hide cursor
	//command(0x0e);						//to show cursor
	//command(0x01);						//to clear LCD completely
}
void command(unsigned char a)
{
	char z;
	z=a & 0xf0;
	command_shift(z);
	z=((a<<4) & 0xf0);
	//z=a & 0xf0;
	command_shift(z);
}
void data(unsigned char a)
{
	char z;
	z=a & 0xf0;
	data_shift(z);
	z=((a<<4) & 0xf0);
	//z=a & 0xf0;
	data_shift(z);
}
void command_shift(unsigned char b)					// to give command to LCD like which position we want to show data
{
	PORTD = b;
	PORTD &= ~(1<<rs);
	PORTD |= (1<<en);
	_delay_ms(1);
	PORTD &= ~(1<<en);
	
}
void data_shift(unsigned char b)
{
	PORTD = b;  
	PORTD |= (1<<rs);
	PORTD |= (1<<en);
	_delay_ms(1);
	PORTD &= ~(1<<en);
	
}