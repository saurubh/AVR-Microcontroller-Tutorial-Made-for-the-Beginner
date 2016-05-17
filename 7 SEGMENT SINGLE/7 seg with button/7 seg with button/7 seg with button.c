/*
 * _7_seg_with_button.c
 *
 * Created: 10/03/2015 11:27:11 AM
 *  Author: Toshiba
 */ 

// prog to increment on button press but as once the button pressed all condi. goes true... so it should be done through array only

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB=0xFE;
	DDRD=0xff;
	PORTD=0x3f;		//0 initially
    while(1)
    {
		if(PINB & 0x01)
		{
			if(PORTD == 0x3f)			
				PORTD=0x06;				//1
			else if(PORTD == 0x06)		
				PORTD=0x5b;				//2
			else if(PORTD == 0x5b)		
				PORTD=0x4f;				//3
			else if(PORTD == 0x4f)		
				PORTD=0x66;				//4
			else if(PORTD == 0x66)		
				PORTD=0x6d;				//5
			else if(PORTD == 0x6d)		
				PORTD=0x7d;				//6
			else if(PORTD == 0x7d)		
				PORTD=0x07;				//7
			else if(PORTD == 0x07)		
				PORTD=0x7f;				//8
			else if(PORTD == 0x7f)		
				PORTD=0x6f;				//9
			else if(PORTD == 0x6f)		
				PORTD=0x3f;				//0
			else
				PORTD=PORTD;			// as it is
			_delay_ms(1000);								
		}	
    }
}