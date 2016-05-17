/*
 * nokia_keypad_interface_with_LCD.c
 *
 * Created: 08/04/2015 12:46:55 PM
 *  Author: Toshiba
 */ 


#include <avr/io.h>
#include <util/delay.h>
 int i=0;
void lcd_init();
void command(unsigned char a);
void data(unsigned char a);

void check();		//keypad button press check
int main(void)
{
	DDRD=0x0f;
	DDRC=0Xff;
	DDRB=0xff;
	lcd_init();
	
    while(1)
    {
		PORTD=0xf0;			//ROWS will be given 0 and COLUMNS will be given 1
							//COLUMNS are assigned as i/p so they will monitor weather i/p data is high or not
							//Rows are assigned as o/p and will logically assign LOW to the respective COLUMN when key is pressed
		if((PIND & 0xf0)!=0xf0);
		{
			check();		
			
		}
	}
}

void check()
{
	
	// check 1
	PORTD=0x0e;
	if ((PIND & 0b00011110)==0b00001110)
	{
		//command(i);
		data('1');
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0b00101110)==0b00001110)
	{
		//command(i);
		data('2');
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0b01001110)==0b00001110)
	{
		//command(i);
		data('3');
		_delay_ms(2000);
		i++;
	}
	
	// check 2
	PORTD=0x0d;
	if ((PIND & 0b00011101)==0b00001101)
	{
		//command(i);
		data('4');
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0b00101101)==0b00001101)
	{
		//command(i);
		data('5');
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0b01001101)==0b00001101)
	{
		//command(0x80);
		data('6');
		_delay_ms(2000);
		i++;
	}
	
	// check 3
	PORTD=0x0b;
	if ((PIND & 0b00011011)==0b00001011)
	{
		//command(0x85);
		data('7');
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0b00101011)==0b00001011)
	{
		//command(0x86);
		data('8');
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0b01001011)==0b00001011)
	{
		//command(0x87);
		data('9');
		_delay_ms(2000);
		i++;
	}
	
	// check 4
	PORTD=0x07;
	if ((PIND & 0b00010111)==0b00000111)
	{
		//command(0x85);
		command('*');
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0b00100111)==0b00000111)
	{
		//command(0x86);
		data('0');
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0b01000111)==0b00000111)
	{
		//command(0x87);
		data('#');
		_delay_ms(2000);
		i++;
	}

	if(i==16)
	{
		i=0;
		command(0x01);
	}
}

// func declaration LCD interface
void lcd_init()							// to initialize LCD
{
	command(0x38);						//LCD init basic command
	command(0x06);						//LCD init basic command
	command(0x0c);						//to hide cursor
	//command(0x0e);						//to show cursor
	//command(0x01);						//to clear LCD completely and reset registers
}
void command(unsigned char a)					// to give command to LCD like which position we want to show data
{
	PORTB=a;						// to send value of a to data pins
	PORTC &= 0xfe;						//Rs = 0	 to tell LCD that value on data pin is command
	PORTC |=0x02;						//Enable=1 to get data transfer pulse(logic 1)
	_delay_ms(10);
	PORTC &=0xfd;						//Enable=0 to get data transfer pulse(logic 0)
}
void data(unsigned char a)
{
	PORTB=a;
	PORTC |=0x01;						// Rs=1	to tell LCD that value on data pins is DATA
	PORTC |=0x02;
	_delay_ms(10);
	PORTC &=0xfd;
}