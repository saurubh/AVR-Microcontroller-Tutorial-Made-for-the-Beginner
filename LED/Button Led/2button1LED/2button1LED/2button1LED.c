/*
 * _2button1LED.c
 *
 * Created: 04/03/2015 12:38:30 PM
 *  Author: Toshiba
 */ 

/* prog to interface 1 LED with buttons as
D0	D1	LED
0	0	OFF
0	1	Previous value
1	0	compliment of Previous value
1	1	ON	*/


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB=0X01;		//PORT B intialised as o/p
	DDRD=0XFC;		//pin D1 & D0 initialised as i/p
	int b=PIND;
	while(1)
	{
		int a= PIND & 0X03;
		_delay_ms(10000);
		if(a==0X00)
		{
			PORTB=0X00;
			b=PORTB;
			_delay_ms(5000);
		}
		else if(a==0X01)
		{
			PORTB=b;
			_delay_ms(5000);
		}
		else if(a==0X02)
		{
			PORTB=~b;
			b=PORTB;
			_delay_ms(5000);
		}
		else if(a==0X03)
		{
			PORTB=0X01;
			b=PORTB;
			_delay_ms(5000);
		}
		
	}
}