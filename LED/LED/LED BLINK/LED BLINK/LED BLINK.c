/*
 * LED_BLINK.c
 *
 * Created: 25/02/2015 12:49:37 PM
 *  Author: Toshiba
 */ 


#include <avr/io.h>
#include <util/delay.h>
void main()
{
	DDRB=0XFF;
    while(1)
    {
        PORTB=0X01;                    //0X01 means port B0 LED on and all off  can also be written as 0b.00000001
		_delay_ms(1000); 
		PORTB=0X02;                    //0X01 means port B1 LED on and all off  can also be written as 0b.00000001
		_delay_ms(1000);
		PORTB=0X04;                    //0X01 means port B2 LED on and all off  can also be written as 0b.00000001
		_delay_ms(1000);
		PORTB=0X08;                    //0X01 means port B3 LED on and all off  can also be written as 0b.00000001
		_delay_ms(1000);
		PORTB=0X10;                    //0X01 means port B4 LED on and all off  can also be written as 0b.00000001
		_delay_ms(1000);
		PORTB=0X20;                    //0X01 means port B5 LED on and all off  can also be written as 0b.00000001
		_delay_ms(1000);
		PORTB=0X40;                    //0X01 means port B6 LED on and all off  can also be written as 0b.00000001
		_delay_ms(1000);
		PORTB=0X80;                    //0X01 means port B7 LED on and all off  can also be written as 0b.00000001
		_delay_ms(1000);
		PORTB=0X40;                    //0X01 means port B6 LED on and all off  can also be written as 0b.00000001
		_delay_ms(1000);
		PORTB=0X20;                    //0X01 means port B5 LED on and all off  can also be written as 0b.00000001
		_delay_ms(1000);
		PORTB=0X10;                    //0X01 means port B4 LED on and all off  can also be written as 0b.00000001
		_delay_ms(1000);
		PORTB=0X08;                    //0X01 means port B3 LED on and all off  can also be written as 0b.00000001
		_delay_ms(1000);
		PORTB=0X04;                    //0X01 means port B2 LED on and all off  can also be written as 0b.00000001
		_delay_ms(1000);
		PORTB=0X02;                    //0X01 means port B1 LED on and all off  can also be written as 0b.00000001
		_delay_ms(1000);
		PORTB=0X01;                    //0X01 means port B0 LED on and all off  can also be written as 0b.00000001
		_delay_ms(1000);
    }
}