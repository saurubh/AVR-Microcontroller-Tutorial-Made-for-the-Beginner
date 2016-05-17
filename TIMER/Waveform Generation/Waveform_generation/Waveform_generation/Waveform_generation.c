/*
 * Waveform_generation.c
 *
 * Created: 12/05/2015 08:27:07 AM
 *  Author: Toshiba
 */ 


#include <avr/io.h>

int main(void)
{
	TCCR1A|=(1<<COM1A0);					// sets COM1A on toggling mode i.e. 
	TCCR1B|=(1<<WGM12)|(1<<CS12);			//setting WGM12-0 100 gives
	OCR1A=31250;
	DDRB|=0X02;
	PORTB|=0X02;
    while(1)
    {
        
    }
}