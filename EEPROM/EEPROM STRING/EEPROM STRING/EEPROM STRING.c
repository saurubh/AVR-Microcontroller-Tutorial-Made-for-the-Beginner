/*
 * EEPROM_STRING.c
 *
 * Created: 20/04/2015 04:33:56 PM
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
void string( char *p);

int count=0,z;
char b[15],a[15];
void EEPROM_write(unsigned int uiAddress, char *p);
void EEPROM_read(unsigned int uiAddress);

int main(void)
{
	DDRB=0xff;      // initialize port B as o/p port
	DDRD=0xff;
	lcd_init();
	int cnt=0;
	//while(1)
	{
		PORTB=0x00;
		EEPROM_write(0x00,"ADITYA MUDGAL");
		EEPROM_read(0x00);
		command(0xc0);
		for(int i=0;i<=z-1;i++)
		{
			data(b[i]);
			if(a[i]==b[i])
				cnt++;					
		}
		if(cnt==z)
			PORTB=0x01;
		else
			PORTB=0x00;
	}
}


// func declaration

//EEPROM write func
void EEPROM_write(unsigned int uiAddress, char *p)
{
	command(0x80);
	uiAddress=0x00;
	while(*p != '\0')
	{
		/* Wait for completion of previous write */
		while(EECR & (1<<EEWE));
		/* Set up address and data registers */
		EEAR = uiAddress;
		EEDR = *p;
		a[count]=*p;
		data(*p);
		*p++;
		uiAddress = uiAddress + 1;
		count++;
		/* Write logical one to EEMWE */
		EECR |= (1<<EEMWE);
		/* Start eeprom write by setting EEWE */
		EECR |= (1<<EEWE);
		z=count;
	}
}

//EEPROM read func
void EEPROM_read(unsigned int uiAddress)
{
	for(int i=0;i<=count-1;i++)
	{
		/* Wait for completion of previous write */
		while(EECR & (1<<EEWE))
		;
		/* Set up address register */
		EEAR = uiAddress;
		uiAddress=uiAddress+1;
		/* Start eeprom read by writing EERE */
		EECR |= (1<<EERE);
		/* Return data from data register */
		b[i]= EEDR;
	}
	count=0;
}

// LCD COMAND SET

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
	command_shift(z);
}
void data(unsigned char a)
{
	char z;
	z=a & 0xf0;
	data_shift(z);
	z=((a<<4) & 0xf0);
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