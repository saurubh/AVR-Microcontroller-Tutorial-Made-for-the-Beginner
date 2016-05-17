/*
 * keypad_interface_easy.c
 *
 * Created: 08/04/2015 11:42:02 AM
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
		if((PORTD & 0xf0)!=0xf0);
		{
			check();		
			
		}
	}
}

void check()
{
	
	char key[16]={'7','8','9','/','4','5','6','*','1','2','3','-','C','0','=','+'};
	// check 1
	PORTD=0xfe;
	if ((PIND & 0xfe)==0x7e)
	{
		//command(i);
		data(key[0]);
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0xfe)==0xbe)
	{
		//command(i);
		data(key[1]);
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0xfe)==0xde)
	{
		//command(i);
		data(key[2]);
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0xfe)==0xee)
	{
		//command(i);
		data(key[3]);
		_delay_ms(2000);
		i++;
	}
	
	// check 2
	PORTD=0xfd;
	if ((PIND & 0xfd)==0x7d)
	{
		//command(i);
		data(key[4]);
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0xfd)==0xbd)
	{
		//command(i);
		data(key[5]);
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0xfd)==0xdd)
	{
		//command(0x80);
		data(key[6]);
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0xfd)==0xed)
	{
		//command(0x88);
		data(key[7]);
		_delay_ms(2000);
		i++;
	}
	
	// check 3
	PORTD=0xdb;
	if ((PIND & 0xdb)==0x7b)
	{
		//command(0x85);
		data(key[8]);
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0xdb)==0xbb)
	{
		//command(0x86);
		data(key[9]);
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0xdb)==0xdb)
	{
		//command(0x87);
		data(key[10]);
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0xdb)==0xeb)
	{
		//command(0x88);
		data(key[11]);
		_delay_ms(2000);
		i++;
	}
	
	// check 4
	PORTD=0xf7;
	if ((PIND & 0xf7)==0x77)
	{
		//command(0x85);
		command(0x01);
		
		i=0;
	}
	else if ((PIND & 0xf7)==0xb7)
	{
		//command(0x86);
		data(key[13]);
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0xf7)==0xd7)
	{
		//command(0x87);
		data(key[14]);
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0xf7)==0xe7)
	{
		//command(0x88);
		data(key[15]);
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