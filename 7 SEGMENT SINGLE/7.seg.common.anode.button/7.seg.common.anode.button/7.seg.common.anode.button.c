/*
 * _7seg.c
 *
 * Created: 10/03/2015 01:10:22 PM
 *  Author: Toshiba
 */ 

// in  common anode segment will glow on 0... so here we had taken the compliment fo the prog of common cathode...
// for compliment ~ symbol is used


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB&=0xFE;
	DDRD=0xff;
	int i=0;
	int a[10]={0x6f,0x7f,0x07,0x7d,0x6d,0x66,0x4f,0x5b,0x06,0x3f};
	while(1)
    {
		if(PINB & 0x01)
		{
			PORTD=~a[i];				// compliment of a[i]
			_delay_ms(1000);
			i++;
			if(i==10)
				i=0;			
		}
			
    }
}