/*
 * BUTTON_LED_INTERFACE.c
 *
 * Created: 04/03/2015 11:11:18 AM
 *  Author: Toshiba 
 */ 

// Led ON when button pressed   
// button D0 and LED B0

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB=0XFF;		//PORT B intialised as o/p
	DDRD&=0XFE;		//PORT D0 initialised as i/p
	
    while(1)
    {
		int a= PIND&0X01;
	     if(a==0X01)
			{
				PORTB=a;
			}
		_delay_ms(3000);
		PORTB=0x00;
    }
}