/*
 * _2interrupts_with_led.c
 *
 * Created: 23/04/2015 04:35:18 PM
 *  Author: Toshiba
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void main(void)
{
	DDRB=0x07;
	GICR=0xc0;						// enables interrupt INT0 and INT1 (p.no. 49 atmega8 data-sheet)
	MCUCR=0x0b;						// detects interrupt INT0 at rising edge and INT1 at falling edge(p.no.66-67 atmega8 data-sheet)
	sei();							//	enables interrupt
					
    while(1)
    {
		PORTB=0x04;	
						
    }
}

ISR(INT0_vect)						//Function definition of interrupt INT0 should be in this
{
	PORTB=0x01;
	_delay_ms(500);
}
ISR(INT1_vect)						//Function definition of interrupt INT1 should be in this
{
	PORTB=0x02;
	_delay_ms(500);
}