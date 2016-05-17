/*
 * digital_clock.c
 *
 * Created: 19/03/2015 10:26:54 AM
 *  Author: Toshiba
 */ 


#include <avr/io.h>
#include <util/delay.h>

void lcd_init();
void command(unsigned char a);
void data(unsigned char a);

int main(void)
{
	DDRD=0xff;		// initialize data port... any change in the port will require change of port name in place of PORTD in command and data function defination as well
	DDRB|=0x03;		// initialize the port and pins on which Rs and E(enable) has to get connected..... any change in this will change the value of PORTB in command and data function defination
	lcd_init();
	char a[13]={'0','1','2','3','4','5','6','7','8','9','0','1','2'};
	while(1)
	{
		command(0x84);		//1st row 5th posi
		data('0');
		command(0x85);
		data('0');
		command(0x86);
		data(':');
		command(0x87);
		data('0');
		command(0x88);
		data('0');
		command(0x89);
		data(':');
		command(0x8a);
		data('0');
		command(0x8b);
		data('0');
		
		for(int i=0;i<2;i++)
		{
			command(0x84);
			data(a[i]);
			for(int j=0;j<13;j++)
			{
				command(0x85);
				data(a[j]);
				for(int k=0;k<6;k++)
				{
					command(0x87);
					data(a[k]);
					for(int l=0;l<10;l++)
					{
						command(0x88);
						data(a[l]);
						for(int m=0;m<6;m++)
						{
							command(0x8a);
							data(a[m]);
							for(int n=0;n<10;n++)
							{
								command(0x8b);
								data(a[n]);
								_delay_ms(6000);
								if(n==10)
								n=0;
								//	command(0x01);					// clear LCD
							}
							if(m==6)
							m=0;
						}
						if(l==10)
						l=0;
					}
					if(k==6)
					k=0;
				}
				if(j==13)
				j=0;
			}
			if(i==2)
			i=0;
		}
	}
}
			




// func declaration
void lcd_init()							// to initialize LCD
{
	command(0x38);						//LCD init basic command
	command(0x06);						//LCD init basic command
	command(0x0c);						//to hide cursor
	//command(0x0e);						//to show cursor
	command(0x01);						//to clear LCD completely
}
void command(unsigned char a)					// to give command to LCD like which position we want to show data
{
	PORTD=a;						// to send value of a to data pins
	PORTB &= 0xfe;						//Rs = 0	 to tell LCD that value on data pin is command
	PORTB |=0x02;						//Enable=1 to get data transfer pulse(logic 1)
	_delay_ms(10);
	PORTB &=0xfd;						//Enable=0 to get data transfer pulse(logic 0)
}
void data(unsigned char a)
{
	PORTD=a;
	PORTB |=0x01;						// Rs=1	to tell LCD that value on data pins is DATA
	PORTB |=0x02;
	_delay_ms(10);
	PORTB &=0xfd;
}