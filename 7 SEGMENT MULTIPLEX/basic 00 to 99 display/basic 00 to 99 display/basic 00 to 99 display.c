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
	DDRB|=0x03;			
	DDRD=0xff;
	int i,j;
	int a[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};		// values in array a[10]={0,1,2,3,4,5,6,7,8,9}
	while(1)
    {		
		
		for(i=0;i<10;i++)
		{
					
			for(j=0;j<10;j++)
			{
				for(int k=0;k<10;k++)
				{
						
					PORTB=0x02;
					PORTD=a[i];
					_delay_ms(100);
			
					PORTB=0x01;
					PORTD=a[j];
					_delay_ms(100);
				}
			}
			j=0;
		}
		i=0;
	
    }
}