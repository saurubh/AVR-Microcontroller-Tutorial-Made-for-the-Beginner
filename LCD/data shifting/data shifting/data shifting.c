/*
 * data_shifting.c
 *
 * Created: 23/03/2015 11:28:45 AM
 *  Author: Toshiba
 */ 
#include <avr/io.h>
#include <util/delay.h>

void lcd_init();
void command(unsigned char a);
void data(unsigned char a);

int main(void)
{
	DDRD=0xff;		// initialize data port... any change in the port will require change of port name in place of PORTD in command and data function defination as well
	DDRB|=0x03;		// initialize the port and pins on which Rs and E(enable) has to get connected..... any change in this will change the value of PORTB in command and data function defination
	lcd_init();
	int a[16]={0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f};
	while(1)
	{
		for(int i=0;i<16;i++)
		{
			command(a[i]);
			data('A');
			_delay_ms(500);
			command(a[i]);
			data(' ');
		}
		
		
		//	command(0x01);					// clear LCD
	}
}


// func declaration
void lcd_init()							// to initialize LCD
{
	command(0x38);						//LCD init basic command
	command(0x06);						//LCD init basic command
	command(0x0c);						//to hide cursor
	//command(0x0e);						//to show cursor
	command(0x01);						//to clear LCD completely
}
void command(unsigned char a)					// to give command to LCD like which position we want to show data
{
	PORTD=a;							// to send value of a to data pins
	PORTB &= 0xfe;						//Rs = 0	 to tell LCD that value on data pin is command
	PORTB |=0x02;						//Enable=1 to get data transfer pulse(logic 1)
	_delay_ms(10);
	PORTB &=0xfd;						//Enable=0 to get data transfer pulse(logic 0)
}
void data(unsigned char a)
{
	PORTD=a;
	PORTB |=0x01;						// Rs=1	to tell LCD that value on data pins is DATA
	PORTB |=0x02;
	_delay_ms(10);
	PORTB &=0xfd;
}