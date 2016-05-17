/*
 * _4bit_LCD.c
 *
 * Created: 30/03/2015 11:01:34 AM
 *  Author: Toshiba
 */ 


#include <avr/io.h>
#include <util/delay.h>
#define rs PD2
#define en PD3
#define rw PB1

void lcd_init();
void command(unsigned char a);
void data(unsigned char a);
void command_shift(unsigned char b);
void data_shift(unsigned char b);

int main(void)
{
	
	DDRD=0xff;		// initialize data port(D4 to D7 as o/p pins)... any change in the port will require change of port name in place of PORTD in command and data function defination as well
	DDRB=0xff;      // initialize port B as o/p port
	PORTB=0x00;		// setting respected pin of PORT B to 0 which is connected to rw of LCD
	
	lcd_init();
	while(1)
	{
		_delay_ms(50);
		command(0x80);		//1st row 1st posi
		data('A');
		data('D');
		data('I');
		data('T');
		data('Y');
		data('A');
		command(0xc0);		//2nd row 1st posi
		data('M');
		data('U');
		data('D');
		data('G');
		data('A');
		data('L');
		
		//	command(0x01);					// clear LCD
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