/*
 * _7seg.c
 *
 * Created: 10/03/2015 01:10:22 PM
 *  Author: Toshiba
 */ 

//increment and decrement of numbers in 7 segment


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB&=0xFC;			
	DDRD=0xff;
	int i=0;
	int a[11]={0x6f,0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	while(1)
    {
		if(PINB & 0x01)					//condition to check switch press condition
		{								// loop for increment
			++i;
			if(i==11)
				i=1;
			PORTD=a[i];
			_delay_ms(1000);
			if(i==10)
				i=0;						
		}
		if(PINB & 0x02)					//condition to check switch press condition 
		{								// loop for decrement
			--i;
			if(i<1)
			i=10;
			PORTD=a[i];
			_delay_ms(1000);
			
		}
    }
}