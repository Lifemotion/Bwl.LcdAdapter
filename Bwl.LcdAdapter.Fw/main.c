#include "board/board.h"
#include "libs/bwl_uart.h"
#include "winstar1602.h"

#define BAUD 9600
#include <util/setbaud.h>



void lcd_power(char state)
{
	setbit(DDRC,5,1);
	setbit(DDRC,4,1);
	setbit(PORTC,5,state);
	setbit(PORTC,4,state);
}

void lcd_power_reset()
{
	lcd_power(0);
	_delay_ms(500);
	lcd_power(1);
}

int main()
{
	wdt_enable(WDTO_8S);
	lcd_power_reset();
	lcd_init();
	uart_init_withdivider(0,UBRR_VALUE);
	
	for (int i=0; i<16; i++)
	{
		lcd_line_1[i]='0'+i;
		lcd_line_2[i]='a'+i;
	}
	
	lcd_writebuffer();
	do 	
	{
		wdt_reset();
		if (uart_receive_line(0))
		{
			if (uart_receive_buffer_0[0]=='^')
			{
				if (uart_receive_buffer_0[1]=='R'){lcd_power_reset();lcd_init();}
				if (uart_receive_buffer_0[1]=='E'){lcd_power(1);lcd_init();}
				if (uart_receive_buffer_0[1]=='D'){lcd_power(0);}
			}else
			{
				
				for(int i=0; i<LCD_LINE_LENGTH; i++)
				{
					lcd_line_1[i]=uart_receive_buffer_0[i];
					lcd_line_2[i]=uart_receive_buffer_0[LCD_LINE_LENGTH+i];
				}
			}
			lcd_writebuffer();
		}
	} while (1);
}