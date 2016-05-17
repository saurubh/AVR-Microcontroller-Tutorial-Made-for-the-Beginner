/*
 * _8_7seg.c
 *
 * Created: 13/03/2015 10:12:14 AM
 *  Author: Toshiba
 */ 

// running 8 7segs as clock	as  _ _ - _ _ - _ _
		

#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRB=0xff;				// 7 seg selection pin
	DDRD=0xff;				// 7 seg data pins
	int i,j,k,l,m,n,stable;
	int a[13]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x3f,0x06,0x5b};		// values in array a[10]={0,1,2,3,4,5,6,7,8,9}
    while(1)
    {
        for(i=0;i<2;i++)											// for loop for 1st 7 seg
		{
			for(j=0;j<13;j++)										// for loop for 2nd 7 seg
			{
				for(k=0;k<6;k++)									// for loop for 4th 7 seg
				{
					for(l=0;l<10;l++)								// for loop for 5th 7 seg	
					{
						for(m=0;m<6;m++)							// for loop for 7th 7 seg
						{
							for(n=0;n<10;n++)						// for loop for 8th 7 seg
							{
								for(stable=0;stable<40;stable++)		// run loop for <40 with frequency 4MHz to run as actual clock with sync secs
								{
									PORTB=0x7f;						// select 7-seg no. 8
									PORTD=a[n];
									_delay_ms(5);
									PORTB=0xbf;						// select 7-seg no. 7
									PORTD=a[m];
									_delay_ms(5);
									PORTB=0xdf;						// select 7-seg no. 6
									PORTD=0x40;
									_delay_ms(5);
									PORTB=0xef;						// select 7-seg no. 5
									PORTD=a[l];
									_delay_ms(5);
									PORTB=0xf7;						// select 7-seg no. 4
									PORTD=a[k];
									_delay_ms(5);
									PORTB=0xfb;						// select 7-seg no. 3
									PORTD=0x40;
									_delay_ms(5);
									PORTB=0xfd;						// select 7-seg no. 2
									PORTD=a[j];
									_delay_ms(5);
									PORTB=0xfe;						// select 7-seg no. 1
									PORTD=a[i];
									_delay_ms(5);	
									
								}								
							}
						}
					}
				}
			}
		}
    }
}