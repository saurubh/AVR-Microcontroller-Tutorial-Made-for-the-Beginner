/*
 * Motors.c
 *
 * Created: 01/04/2015 12:31:36 PM
 *  Author: Toshiba
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRD=0xff;
	while(1)
    {
        PORTD=0b00000101;
		_delay_ms(10000);
		PORTD=0b00001010;
		_delay_ms(10000);
		PORTD=0b00001001;
		_delay_ms(10000);
		PORTD=0b00000110;
		_delay_ms(10000);
    }
}