/*
 * rise_fal_duty.c
 *
 * Created: 06/05/2015 04:51:02 PM
 *  Author: Toshiba
 */ 


#define F_CPU 8000000

#include <avr/io.h>
#include <avr/interrupt.h>
void USART_Init(unsigned int ubrr);
void USART_Transmit(unsigned char data);
void transmit_str(char *p);


int main(void)
{
	DDRB=0x00;
	USART_Init(51);
	TCCR1B=0x04;				// setting falling edge trigger(bit 6) and pre-scaler to 256
	
	long int a,b,c,x,duty,rise,fal,tot;	
    
	while(1)
    {
		TCNT1=0;	
	// this detects the first falling edge
		while(!(TIFR&(1<<ICF1)));
		TCCR1B|=0x40;							// setting rising edge triggering
		TIFR|=(1<<ICF1);						// reseting input capture flag
	// here we detecting rising edge
        while(!(TIFR&(1<<ICF1)));
		TIFR|=(1<<ICF1);						// reseting input capture flag
		TCCR1B&=0x0f;							// setting falling edge triggering
		a=ICR1;									// saving value of ICR1(TCNT1 stored at edge trigger) in variable
	// here we detecting falling edge
		while(!(TIFR&(1<<ICF1)));
		TIFR|=(1<<ICF1);						// reseting input capture flag
		TCCR1B|=0x40;							// setting rising edge triggering
		b=ICR1;
	// here we detecting rising edge
		while(!(TIFR&(1<<ICF1)));
		TIFR|=(1<<ICF1);						// reseting input capture flag
		TCCR1B&=0x0f;							// setting falling edge triggering
		c=ICR1;
		
	// we are using rising falling rising format with variables as a b c respectively	
		tot=c-a;
		rise=b-a;
		fal=c-b;
		
		duty=(rise*100)/tot;
		transmit_str("duty rate:");
		x=(duty/10)+48;
		USART_Transmit(x);
		x=(duty%10)+48;
		USART_Transmit(x);
		USART_Transmit('%');
		USART_Transmit(' ');
		USART_Transmit(' ');
		
		rise=rise*32000;
		transmit_str("Rise time: 0.");
		x=(rise/100000000)+48;
		USART_Transmit(x);
		rise=rise%100000000;
		x=(rise/10000000)+48;
		USART_Transmit(x);
		rise=rise%10000000;
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
		rise=rise%100;
		x=(rise/10)+48;
		USART_Transmit(x);
		x=(rise%10)+48;
		USART_Transmit(x);
		transmit_str("sec");
		USART_Transmit(' ');
		USART_Transmit(' ');
		
		fal=fal*32000;
		transmit_str("Fall time: 0.");
		x=(fal/100000000)+48;
		USART_Transmit(x);
		fal=fal%100000000;
		x=(fal/10000000)+48;
		USART_Transmit(x);
		fal=fal%10000000;
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
		fal=fal%100;
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
	/* Set duty rate */
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
		p++;
	}
}