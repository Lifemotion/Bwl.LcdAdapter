#include "board.h"

void set_led (byte state)
{
	setbit(DDRB,5,1);
	setbit(PORTB,5,state);
}

int get_state_button(void)
{
	setbit(DDRB,4,0);
	setbit(PORTB,4,1);
	return getbit(PINB,4);	
}

int get_gps_pps()
{
	setbit(DDRD,4,0);
	setbit(PORTD,4,0);
	return getbit(PIND,4);
}

void gps_reset (byte state)
{
	_delay_ms(100);
	setbit(DDRD,6,1);
	setbit(PORTD,6,0);
	_delay_ms(200);
	setbit(DDRD,6,1);
	setbit(PORTD,6,1);	
}

void gps_disable()
{
		setbit(DDRD,6,1);
		setbit(PORTD,6,0);
}

void var_delay_ms(int ms)
{
	for (int i=0; i<ms; i++)_delay_ms(1.0);
}