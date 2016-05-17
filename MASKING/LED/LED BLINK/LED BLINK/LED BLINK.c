/*
 * LED_BLINK.c
 *
 * Created: 27/02/2015 11:15:27 AM
 *  Author: Toshiba
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB|=0X01;
	while(1)
    {
        PORTB|=0X01;
		_delay_ms(1000);
		PORTB&=0XFE;
		_delay_ms(1000);
    }
}