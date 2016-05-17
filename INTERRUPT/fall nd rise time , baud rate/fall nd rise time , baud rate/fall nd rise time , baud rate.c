/*
 * fall_nd_rise_time___baud_rate.c
 *
 * Created: 06/05/2015 11:44:48 AM
 *  Author: Toshiba
 */ 


#define F_CPU 8000000

#include <avr/io.h>
#include <avr/interrupt.h>
void USART_Init(unsigned int ubrr);
void USART_Transmit(unsigned char data);



int main(void)
{
	DDRB=0x00;
	USART_Init(51);
	TCCR1B=0x04;
	//TIFR=(1<<ICF1);
	long int a,b,c,x,tot,rise,fal;	
    
	while(1)
    {
		TCNT1=0;
		while(!(TIFR&(1<<ICF1)));
		TCCR1B|=0x40;
		TIFR=(1<<ICF1);

        while(!(TIFR&(1<<ICF1)));
		TIFR|=(1<<ICF1);
		TCCR1B&=0x0f;
		a=ICR1;
		
		while(!(TIFR&(1<<ICF1)));
		TIFR|=(1<<ICF1);
		TCCR1B|=0x40;
		b=ICR1;
		
		while(!(TIFR&(1<<ICF1)));
		TIFR|=(1<<ICF1);
		TCCR1B&=0x0f;
		c=ICR1;
		
		tot=c-a;
		rise=b-a;
		fal=c-b;
		
		//tot=tot*256;
		x=(tot/10000000)+48;
		USART_Transmit(x);
		tot=tot%10000000;
		x=(tot/1000000)+48;
		USART_Transmit(x);
		tot=tot%1000000;
		x=(tot/100000)+48;
		USART_Transmit(x);
		tot=tot%100000;
		x=(tot/10000)+48;
		USART_Transmit(x);
		tot=tot%10000;
		x=(tot/1000)+48;
		USART_Transmit(x);
		tot=tot%1000;
		x=(tot/100)+48;
		USART_Transmit(x);
		tot=tot%100;							// we devied by 2 as LM35 gives double value of the actual value i.e.
		x=(tot/10)+48;
		USART_Transmit(x);
		x=(tot%10)+48;
		USART_Transmit(x);
		USART_Transmit(' ');
		USART_Transmit(' ');
		
		rise=rise*390;
		transmit_str("Rise time: 0.");
// 		x=(rise/1000000000)+48;
// 		USART_Transmit(x);
// 		rise=rise%1000000000;
// 		x=(rise/100000000)+48;
// 		USART_Transmit(x);
// 		rise=rise%100000000;
// 		x=(rise/10000000)+48;
// 		USART_Transmit(x);
// 		rise=rise%10000000;
		x=(rise/1000000)+48;
		USART_Transmit(x);
		rise=rise%1000000;
		x=(rise/100000)+48;
		USART_Transmit(x);
		rise=rise%100000;
		x=(rise/10000)+48;
		USART_Transmit(x);
		rise=rise%10000;
		x=(rise/1000)+48;
		USART_Transmit(x);
		rise=rise%1000;
		x=(rise/100)+48;
		USART_Transmit(x);
		rise=rise%100;							// we devied by 2 as LM35 gives double value of the actual value i.e.
		x=(rise/10)+48;
		USART_Transmit(x);
		x=(rise%10)+48;
		USART_Transmit(x);
		transmit_str("sec");
		USART_Transmit(' ');
		USART_Transmit(' ');
		
		fal=fal*390;
		transmit_str("Fall time: 0.");
// 		x=(fal/1000000000)+48;
// 		USART_Transmit(x);
// 		fal=fal%1000000000;
// 		x=(fal/100000000)+48;
// 		USART_Transmit(x);
// 		fal=fal%100000000;
// 		x=(fal/10000000)+48;
// 		USART_Transmit(x);
// 		fal=fal%10000000;
		x=(fal/1000000)+48;
		USART_Transmit(x);
		fal=fal%1000000;
		x=(fal/100000)+48;
		USART_Transmit(x);
		fal=fal%100000;
		x=(fal/10000)+48;
		USART_Transmit(x);
		fal=fal%10000;
		x=(fal/1000)+48;
		USART_Transmit(x);
		fal=fal%1000;
		x=(fal/100)+48;
		USART_Transmit(x);
		fal=fal%100;							// we devied by 2 as LM35 gives double value of the actual value i.e.
		x=(fal/10)+48;
		USART_Transmit(x);
		x=(fal%10)+48;
		USART_Transmit(x);
		transmit_str("sec");
		USART_Transmit(' ');
		USART_Transmit(' ');
		
    }
}

// func declaration
//USART init,transmitt, receiver
void USART_Init( unsigned int ubrr)
{
	/* Set baud rate */
	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}
void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
	;
	/* Put data into buffer, sends the data */
	UDR = data;
}
void transmit_str(char *p)
{
	while(*p!= '\0')
	{
		USART_Transmit(*p);
		*p++;
	}
}