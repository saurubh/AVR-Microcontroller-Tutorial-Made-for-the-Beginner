/*
 * LCD.c
 *
 * Created: 18/03/2015 12:16:12 PM
 *  Author: Toshiba
 */ 


#include <avr/io.h>
#include <util/delay.h>

void lcd_init();
void command(unsigned char a);
void data(unsigned char a);
void string(unsigned char *p);

int main(void)
{
	DDRD=0xff;
	DDRB=0xff;
	lcd_init();
	
    string("ADITYA");
}

// func declaration
void lcd_init()							// to initialize LCD
{
	command(0x38);						//LCD init basic command
	command(0x06);						//LCD init basic command
	//command(0x0c);						//to hide cursor
	command(0x0e);						//to show cursor
	command(0x01);						//to erase LCD data completely
}
void command(unsigned char a)			// to give command to LCD like which position we want to show data
{
								// to send value of a to data pins
	PORTB &=0xfe;						//Rs = 0	 to tell LCD that value on data pin is command
	PORTB |=0x02;						//Enable=1 to get data transfer pulse(logic 1)
	_delay_ms(10);
	PORTB &=0xfd;
	PORTD=a;						//Enable=0 to get data transfer pulse(logic 0)
}
void data(unsigned char a)
{
	PORTD=a;
	PORTB |=0x01;						// Rs=1	to tell LCD that value on data pins is DATA
	PORTB |=0x02;
	_delay_ms(10);
	PORTB &=0xfd;
}
void string(unsigned char *p)
{
	//int i=0;
	while(*p!= '\0')
	{
		data(*p);
		*p++;
	}
}