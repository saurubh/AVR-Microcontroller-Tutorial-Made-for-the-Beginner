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
	int count=0;
	//PORTD=0x3f;		//0 initially
    while(1)
    {
		int b=0;
		b=PINB & 0x01;
		if(b == 0x01)
		{
			if(count==1)			
				PORTD=0x06;				//1
			else if(count==2)		
				PORTD=0x5b;				//2
			else if(count==3)
				PORTD=0x4f;				//3
			else if(count==4)
				PORTD=0x66;				//4
			else if(count==5)
				PORTD=0x6d;				//5
			else if(count==6)
				PORTD=0x7d;				//6
			else if(count==7)
				PORTD=0x07;				//7
			else if(count==8)		
				PORTD=0x7f;				//8
			else if(count==9)		
				PORTD=0x6f;				//9
			else if(count==10)		
				PORTD=0x3f;				//0
			_delay_ms(1000);
			count++;
	     if(count==10)
			count=0;
		}
    }
}