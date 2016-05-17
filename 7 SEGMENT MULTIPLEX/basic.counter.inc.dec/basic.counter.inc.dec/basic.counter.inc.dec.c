/*
 * basic.c
 *
 * Created: 16/03/2015 11:56:45 PM
 *  Author: Toshiba
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB|=0x03;		
	// 0x03 means 0000 0011 and it enables 1st and 2nd pin as o/p pin(coz 1 means o/p only remaining pins remains unchanged due to use of ORing function. as ORing means addition
	DDRB&=0xfb;
	// 0xfb means 1111 1011 and it enables 3rd pin as i/p pin only remaining pins remains unchanged due to use of ANDing function. as ANDing means product
	DDRD=0xff;
	int i=0,j=0;
	int a[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};		// values in array a[10]={0,1,2,3,4,5,6,7,8,9}
    while(1)
    {
	// for continues show/display of data	
     	PORTB=0x01;				// 1st 7seg				
     	PORTD=a[i];
     	_delay_ms(100);
     	
     	PORTB=0x02;				// 2nd 7seg
     	PORTD=a[j];
     	_delay_ms(100);
		 if(PINB & 0x04)
		{

		//	now it inc the values of i and j as per requirement and calculation
			i++;
			if(i==10)
			{
				i=0;
				j++;
				if(j==10)
					j=0;				
			}
		}
	}
}