/*
 * sand_glass.c
 *
 * Created: 26/02/2015 10:53:21 AM
 *  Author: Toshiba
 */ 


#include <avr/io.h>
#include <util/delay.h>
void main()
{
	DDRB=0XFF;
	
	while(1)
	{
		PORTB=0x01;			// ALL LED BLINK
		_delay_ms(1000);
		PORTB=0X02;
		_delay_ms(1000);
		PORTB=0X04;
		_delay_ms(1000);
		PORTB=0X08;
		_delay_ms(1000);
		PORTB=0X10;
		_delay_ms(1000);
		PORTB=0X20;
		_delay_ms(1000);
		PORTB=0X40;
		_delay_ms(1000);
		PORTB=0X80;
		_delay_ms(1000);
		
		// LED 8 WILL BE ON AND ALL OTHER BLINK
		
		PORTB=0X81;
		_delay_ms(1000);
		PORTB=0X82;
		_delay_ms(1000);
		PORTB=0X84;
		_delay_ms(1000);
		PORTB=0X88;
		_delay_ms(1000);
		PORTB=0X90;
		_delay_ms(1000);
		PORTB=0XA0;
		_delay_ms(1000);
		PORTB=0XC0;
	    _delay_ms(1000);
		
		// LED 7 & 8 WILL BE ON AND ALL OTHER BLINK
		
		PORTB=0XC1;
		_delay_ms(1000);
		PORTB=0XC2;
		_delay_ms(1000);
		PORTB=0XC4;
		_delay_ms(1000);
		PORTB=0XC8;
		_delay_ms(1000);
		PORTB=0XD0;
		_delay_ms(1000);
		PORTB=0XE0;
		_delay_ms(1000);
				
		// LET 6,7,8 WILL BE ON AND ALL OTHER BLINK
		
		PORTB=0XE1;
		_delay_ms(1000);
		PORTB=0XE2;
		_delay_ms(1000);
		PORTB=0XE4;
		_delay_ms(1000);
		PORTB=0XE8;
		_delay_ms(1000);
		PORTB=0XF0;
		_delay_ms(1000);
		
		// LET 5,6,7,8 WILL BE ON AND ALL OTHER BLINK
		
		PORTB=0XF1;
		_delay_ms(1000);
		PORTB=0XF2;
		_delay_ms(1000);
		PORTB=0XF4;
		_delay_ms(1000);
		PORTB=0XF8;
		_delay_ms(1000);
		
		// LET 4,5,6,7,8 WILL BE ON AND ALL OTHER BLINK
		
		PORTB=0XF9;
		_delay_ms(1000);
		PORTB=0XFA;
		_delay_ms(1000);
		PORTB=0XFC;
		_delay_ms(1000);
		
		// LET 3,4,5,6,7,8 WILL BE ON AND ALL OTHER BLINK
		
		PORTB=0XFD;
		_delay_ms(1000);
		PORTB=0XFE;
		_delay_ms(1000);
		
		// LET 2,3,4,5,6,7,8 WILL BE ON AND ALL OTHER BLINK
		
		PORTB=0XFF;
		_delay_ms(1000);
	}
}