/*
 * LCD_display.c
 *
 * Created: 21/04/2015 05:24:32 PM
 *  Author: Toshiba
 */ 



#include <avr/io.h>
#include <util/delay.h>

void USART_Init(unsigned int ubrr);
void USART_Transmit(unsigned char data);
unsigned char USART_Receive( void );

#define rs PB0
#define en PB1
void lcd_init();
void command(unsigned char a);
void display(unsigned char a);
void command_shift(unsigned char b);
void data_shift(unsigned char b);

int main(void)
{
	
	DDRB=0xff;		// initialize data port(D4 to D7 as o/p pins)... any change in the port will require change of port name in place of PORTB in command and data function defination as well
	USART_Init(6);
	lcd_init();
	while(1)
	{
		
		unsigned char a=USART_Receive();
		display(a);
		
		
	}
}


// func declaration
//USART init,transmitt, receiver
void USART_Init( unsigned int ubrr)
{
	/* Set baud rate */
	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}
void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
	;
	/* Put data into buffer, sends the data */
	UDR = data;
}
unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Get and return received data from buffer */
	return UDR;
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
void display(unsigned char a)
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
	PORTB = b;
	PORTB &= ~(1<<rs);
	PORTB |= (1<<en);
	_delay_ms(1);
	PORTB &= ~(1<<en);
	
}
void data_shift(unsigned char b)
{
	PORTB = b;
	PORTB |= (1<<rs);
	PORTB |= (1<<en);
	_delay_ms(1);
	PORTB &= ~(1<<en);
	
}