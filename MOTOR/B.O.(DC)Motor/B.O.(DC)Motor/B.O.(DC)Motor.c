/*
 * B.c
 *
 * Created: 02/04/2015 10:26:34 AM
 *  Author: Toshiba
 */ 
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD=0x0f;		// initialize data port... any change in the port will require change of port name in place of PORTD in command and data function defination as well
	while(1)
	{
		int a=PIND & 0xf0;				// assigns MSB of the Port D	e.g. is PIND=01011100 then a=01010000
		int b=a>>4;						// right shifts the data of Port D	e.g.b=00000101
		int c=a|b;						// c=a+b;(ORING)	c=01010101
		PORTD=c;				
	}
}