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

int main(void)
{
	DDRD=0xff;
	DDRB|=0x03;
	lcd_init();
    //while(1)
    //{
		command(0x0e);
		_delay_ms(50);
		command(0x80);		//1st row 1st posi
		data('A');
		_delay_ms(50);
		command(0x0e);
		_delay_ms(50);
		command(0x81);		//1st row 2nd posi
		data('D');
		_delay_ms(50);
		command(0x0e);
		_delay_ms(50);
		command(0x82);		//1st row 3rd posi
		data('I');
		_delay_ms(50);
		command(0x0e);
		_delay_ms(50);
		command(0x83);		//1st row 4th posi
		data('T');
		_delay_ms(50);
		command(0x0e);
		_delay_ms(50);
		command(0x84);		//1st row 5th posi    
		data('Y');
		_delay_ms(50);
		command(0x0e);
		_delay_ms(50);
		command(0x85);		//2nd row 6th posi
		// to select the position in 1st row 8 will remain constant and second part will go from 0 to f
		
		data('A');
		_delay_ms(50);
		command(0x0e);
		_delay_ms(50);
		command(0xc0);		//2nd row 1st posi
		data('M');
		_delay_ms(50);
		command(0x0e);
		_delay_ms(50);
		command(0xc1);		//2nd row 2nd posi
		data('U');
		_delay_ms(50);
		command(0x0e);
		_delay_ms(50);
		command(0xc2);		//2nd row 3rd posi
		data('D');
		_delay_ms(50);
		command(0x0e);
		_delay_ms(50);
		command(0xc3);		//2nd row 4th posi
		data('G');
		_delay_ms(50);
		command(0x0e);
		_delay_ms(50);
		command(0xc4);		//2nd row 5th posi
		data('A');
		_delay_ms(50);
		command(0x0e);
		_delay_ms(50);
		command(0xc5);		//2nd row 6th posi
		data('L');
		_delay_ms(50);
		command(0x0e);
		_delay_ms(500);
	//	command(0x01);		// clear LCD
		// to select the position in 2nd row c will remain constant and second part will go from 0 to f
//	}
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