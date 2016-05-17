/*
 * b0_on_b1_blink.c
 *
 * Created: 27/02/2015 11:31:06 AM
 *  Author: Toshiba
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
   DDRB|=0x03;
    while(1)
    {
        PORTB|=0X03;			//LED b0 and b1 ON
		_delay_ms(1000);
		PORTB&=0X01;			// LED b0 on b1 off
		_delay_ms(1000);
    }
}