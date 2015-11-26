#ifndef BOARD_H_
#define BOARD_H_

#define F_CPU 4000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/wdt.h>

#include <stdlib.h>
#include <string.h>

#define getbit(port, bit)		((port) &   (1 << (bit)))
#define setbit(port,bit,val)	{if ((val)) {(port)|= (1 << (bit));} else {(port) &= ~(1 << (bit));}}

typedef unsigned char byte;

#endif /* BOARD_H_ */