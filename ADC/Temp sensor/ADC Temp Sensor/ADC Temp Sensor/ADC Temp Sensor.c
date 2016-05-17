/*
 * ADC_Temp_Sensor.c
 *
 * Created: 14/04/2015 11:32:53 AM
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
	int a,b;
	lcd_init();
	while(1)
	{
		ADMUX=0x40;
		ADCSRA|=0xe7;
		
		while((ADCSRA & (1<<ADIF))==0);		 //it waits until condi. satisfies i.e. remains in while loop until conversion completes
		// while(~(ADCSRA & (1<<ADIF))); can also be written as ADIF will be 0 untill conversion continues and and ADIF becomes 1 when conversion completes and hence it terminates from the loop 
		int adc0=ADC;
			
		ADMUX=0x41;
		ADCSRA|=0xe7;
		command(0x80);
		while((ADCSRA & (1<<ADIF))==0);		 //it waits until condi. satisfies i.e. remains in while loop until conversion completes
		// while(~(ADCSRA & (1<<ADIF))); can also be written as ADIF will be 0 untill conversion continues and and ADIF becomes 1 when conversion completes and hence it terminates from the loop
		int adc1=ADC;
			
			
			a=adc1-adc0;
			a=a*.49;							// we multiplies by .49 as ADC gives almost double the value of the temp.
			
			if(a>=0)
				data('-');
			else
				{
					data('+');
					a=a*(-1);
				}
			
			b=a/100;
			data(b);
			a=a%100;
			b=(a/10)+48;
			data(b);
			b=(a%10)+48;
			data(b);
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