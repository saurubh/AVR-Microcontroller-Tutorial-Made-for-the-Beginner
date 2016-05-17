/*
 * sand_glass.c
 *
 * Created: 27/02/2015 11:38:17 AM
 *  Author: Toshiba
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
//#define powf	pow(int,int)	
int main(void)
{
	DDRB=0Xff;
	int z,y;
    while(1)
    {	//PORTB|=0x01;
		//_delay_ms(1000);
		//PORTB&=0Xfe;
        for(int i=0;i<8;i++)
		{
			z=pow(2,i);
			PORTB |= z;	
			_delay_ms(1000);
			y=255-z;
			PORTB &= y;
		//	_delay_ms(1000);
		}
    }
}