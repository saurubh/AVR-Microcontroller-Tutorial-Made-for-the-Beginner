/*
 * _2button2LED.c
 *
 * Created: 04/03/2015 11:59:15 AM
 *  Author: Toshiba
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB=0XFF;		//PORT B intialised as o/p
	DDRD=0XFC;		//pin D1 & D0 initialised as i/p
	
    while(1)
    {
		int a= PIND & 0X03;
	     if(a==0X01)
			{
				PORTB=a;
			}
		else if(a==0X02)
			{
				PORTB=a;
			}
		_delay_ms(1000);
		PORTB=0x00;
	}
}