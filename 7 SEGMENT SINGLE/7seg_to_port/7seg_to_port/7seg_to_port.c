/*
 * _7seg_to_port.c
 *
 * Created: 09/03/2015 06:46:44 PM
 *  Author: Toshiba
 */ 

// pROGRAMMING FOR COMMON CATHODE..... SEGMENT GLOWS AT 1
// FOR COMMON ANODE....... SEGMENT GLOWS ON 0 INSTEAD OF 1

/*common cathode
for	hex	g	f	e	d	c	b	a	
0	3f	0	1	1	1	1	1	1	
1	06	0	0	0	0	1	1	0			
2	5b	1	0	1	1	0	1	1		
3	4f	1	0	0	1	1	1	1		
4	66	1	1	0	0	1	1	0		
5	6d	1	1	0	1	1	0	1		
6	7d	1	1	1	1	1	0	1		
7	07	0	0	0	0	1	1	1		
8	7f	1	1	1	1	1	1	1		
9	6f	1	1	0	1	1	1	1	
*/


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD=0xff;
    while(1)
    {
		PORTD=0x00;		//display . of the 7 segment
		_delay_ms(1000);
		PORTD=0x3f;		//displays 0
		_delay_ms(1000);
		PORTD=0x00;	
		_delay_ms(1000);
		PORTD=0x06;		//displays 1
		_delay_ms(1000);
		PORTD=0x00;
		_delay_ms(1000);
		PORTD=0x5b;		//displays 2
		_delay_ms(1000);
		PORTD=0x00;
		_delay_ms(1000);
		PORTD=0x4f;		//displays 3
		_delay_ms(1000);
		PORTD=0x00;
		_delay_ms(1000);
		PORTD=0x66;		//displays 4
		_delay_ms(1000);
		PORTD=0x00;
		_delay_ms(1000);
		PORTD=0x6d;		//displays 5
		_delay_ms(1000);
		PORTD=0x00;
		_delay_ms(1000);
		PORTD=0x7d;		//displays 6
		_delay_ms(1000);
		PORTD=0x00;
		_delay_ms(1000);
		PORTD=0x07;		//displays 7
		_delay_ms(1000);
		PORTD=0x00;
		_delay_ms(1000);
		PORTD=0x7f;		//displays 8
		_delay_ms(1000);
		PORTD=0x00;
		_delay_ms(1000);
		PORTD=0x6f;		//displays 9
		_delay_ms(1000);
	}
}