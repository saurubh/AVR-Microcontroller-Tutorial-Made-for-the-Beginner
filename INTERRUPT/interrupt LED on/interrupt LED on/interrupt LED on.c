/*
 * interrupt_LED_on.c
 *
 * Created: 23/04/2015 03:55:40 PM
 *  Author: Toshiba
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void main(void)
{
	DDRB=0x11;
	GICR=0x40;						// enables interrupt INT0 (p.no. 49 atmega8 data-sheet)
	MCUCR=0x03;						// detects interrupt INT0 at rising edge(p.no.66-67 atmega8 data-sheet)
	sei();							//	enables interrupt
					
    while(1)
    {
		PORTB=0x10;	
						
    }
}

ISR(INT0_vect)						//Function definition of interrupt should be in this
{
	PORTB=0x01;
	_delay_ms(500);
}