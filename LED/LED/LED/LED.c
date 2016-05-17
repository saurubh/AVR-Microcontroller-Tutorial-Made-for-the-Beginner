/*
 * LED.c
 *
 * Created: 25/02/2015 11:43:55 AM
 *  Author: Toshiba
 */ 


#include <avr/io.h>
#include <util/delay.h>

void main(void)
{
	DDRB=0XFF;
    while(1)
    {
       PORTB=0XFF;     //glow all LED's
       _delay_ms(1000);
	   PORTB=0X00;
	   _delay_ms(1000);
	}
	
}