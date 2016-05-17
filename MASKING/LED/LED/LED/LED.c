/*
 * LED.c
 *
 * Created: 27/02/2015 11:09:22 AM
 *  Author: Toshiba
 */ 


#include <avr/io.h>

void main()
{
	DDRB|= 0X01;
    while(1)
    {
        PORTB|=0X01;
    }
}