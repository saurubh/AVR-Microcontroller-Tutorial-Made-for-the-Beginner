/*
 * Clock_8_7seg_.c
 *
 * Created: 27/04/2015 03:41:59 PM
 *  Author: Toshiba
 */ 


// running 8 7segs as clock	as  _ _ - _ _ - _ _
// accurately working		
#define F_CPU 8000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int i=0,j=0,k=0,l=0,m=0,n=0,r=0;
int a[13]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x3f,0x06,0x5b};		// values in array a[10]={0,1,2,3,4,5,6,7,8,9,0,1,2}


int main(void)
{
	DDRB=0xff;				// 7 seg selection pin
	DDRD=0xff;				// 7 seg data pins
	TCCR1B=0x04;
	TIMSK=(1<<OCIE1B);
	OCR1B=25000;
	sei();					// enables interrupt function whenever interrupt comes
	while(1)
    {
		PORTB=0x7f;						// select 7-seg no. 1
		PORTD=a[i];	
		_delay_us(100);								
		PORTB=0xbf;						// select 7-seg no. 2
		PORTD=a[j];									
		_delay_us(100);
		PORTB=0xdf;						// select 7-seg no. 3
		PORTD=0x40;									
		_delay_us(100);
		PORTB=0xef;						// select 7-seg no. 4
		PORTD=a[k];									
		_delay_us(100);
		PORTB=0xf7;						// select 7-seg no. 5
		PORTD=a[l];									
		_delay_us(100);
		PORTB=0xfb;						// select 7-seg no. 6
		PORTD=0x40;									
		_delay_us(100);
		PORTB=0xfd;						// select 7-seg no. 7
		PORTD=a[m];									
		_delay_us(100);
		PORTB=0xfe;						// select 7-seg no. 8
		PORTD=a[n];		
		_delay_us(100);
    }
}


ISR(TIMER1_COMPB_vect)						//Function definition of interrupt INT0 should be in this
{
	TIFR=(1<<OCF1B);					
	TCNT1=0x00;
	
	i++;
	if(i==10)
	{
		i=0;
		j++;
		if(j==6)
		{
			j=0;
			k++;
			if(k==10)
			{
				k=0;
				l++;
				if(l==6)
				{
					l=0;
					r++;
					if(r<10)
					{
						m++;
						
					}
					else if(r==10)
					{
						m=0;
						n++;
						
					}
					else if(r<13)
					{
						m++;
						
					}
					else if(r==13)
					{
						m=0;
						n=0;
						r=0;
					}
					else
					{
						return;
					}
					
				}
				else
				{
					return;
				}
			}
			else
			{
				return;
			}
		}
		else
		{
			return;
		}
	}
	else
	{
		return;
	}
}