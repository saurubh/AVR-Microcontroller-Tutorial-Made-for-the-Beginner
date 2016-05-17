/*
 * Keypad_Interfacing.c
 *
 * Created: 03/04/2015 09:27:21 AM
 *  Author: Toshiba
 */ 

//	the default frequency of the delay is 1MHz and in this way it sets the frequency to 8MHz
//  6 zeroes is coz mega is 10^6
#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
char p,q,r,s;
int i=0,n=0;
void lcd_init();
void command(unsigned char a);
void data(unsigned char a);

void add(int);
void sub(int);
void mul(int);
void div(int);
void reset(void);
void result(void);
int check();			 //keypad button press check
int main(void)
{
	
	DDRD=0x0f;
	DDRC=0Xff;
	DDRB=0xff;
	lcd_init();
	int a,x;
	int first[10],second[10],res[20];
    while(1)
    {
		PORTD=0xf0;			//ROWS will be given 0 and COLUMNS will be given 1
							//COLUMNS are assigned as i/p so they will monitor weather i/p data is high or not
							//Rows are assigned as o/p and will logically assign LOW to the respective COLUMN when key is pressed
		if((PIND & 0xf0)!=0xf0);
		{
			
			a=check();
			if(a==99)
			{
				div(x);
			}
			else if(a==88)
			{
				mul(x);
			}
			else if(a==77)
			{
				sub(x);
			}
			else if(a==66)
			{
				add(x);
			}
			else if(a==888)
			{
				result();
			}
			else
			{
				calculation();
				n++;
			}
		
		}
	}
}


//function for the operators to be done
void add(int a)
{
	
}
void sub(int a)
{
	
}
void mul(int a)
{
	
}
void div(int a)
{
	
}



// function to check which key is pressed
int check()
{
	
	//char key[16]={'7','8','9','/','4','5','6','*','1','2','3','-','C','0','=','+'};
	// check 1
	PORTD=0x0e;
	if ((PIND & 0b00011110)==0b00001110)
	{
		//command(i);
		data('7');
		return (7);
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0b00101110)==0b00001110)
	{
		//command(i);
		data('8');
		return (8);
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0b01001110)==0b00001110)
	{
		//command(i);
		data('9');
		return (9);
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0b10001110)==0b00001110)
	{
		//command(i);
		data('/');
		return (99);
		_delay_ms(2000);
		i++;
	}
	
	// check 2
	PORTD=0x0d;
	if ((PIND & 0b00011101)==0b00001101)
	{
		//command(i);
		data('4');
		return (4);
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0b00101101)==0b00001101)
	{
		//command(i);
		data('5');
		return (5);
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0b01001101)==0b00001101)
	{
		//command(0x80);
		data('6');
		return (6);
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0b10001101)==0b00001101)
	{
		//command(0x88);
		data('*');
		return (88);
		_delay_ms(2000);
		i++;
	}
	
	// check 3
	PORTD=0x0b;
	if ((PIND & 0b00011011)==0b00001011)
	{
		//command(0x85);
		data('1');
		return (1);
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0b00101011)==0b00001011)
	{
		//command(0x86);
		data('2');
		return (2);
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0b01001011)==0b00001011)
	{
		//command(0x87);
		data('3');
		return (3);
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0b10001011)==0b00001011)
	{
		//command(0x88);
		data('-');
		return (77);
		_delay_ms(2000);
		i++;
	}
	
	// check 4
	PORTD=0x07;
	if ((PIND & 0b00010111)==0b00000111)
	{
		//command(0x85);
		command(0x01);
		return (999);						// this is for the button ON/C
		reset();
		i=0;
	}
	else if ((PIND & 0b00100111)==0b00000111)
	{
		//command(0x86);
		data('0');
		return (0);
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0b01000111)==0b00000111)
	{
		//command(0x87);
		return (888);						//	this is for symbol '='
		_delay_ms(2000);
		i++;
	}
	else if ((PIND & 0b10000111)==0b00000111)
	{
		//command(0x88);
		data('+');
		return (66);
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

