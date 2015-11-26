/*
 * Bwl UART lib for AVR: mega48/88/168/328
 *
 * Author: Igor Koshelev and others
 * Licensed: open-source Apache license
 *
 * Version: 29.07.2015
 */ 

#ifndef BWL_UART_H_
#define BWL_UART_H_

void uart_init_withdivider_x2(unsigned char port, unsigned int ubrr);
void uart_init_withdivider(unsigned char port,unsigned int ubrr);
void uart_send(unsigned char port, unsigned char byte );
unsigned char uart_get(unsigned char port );
unsigned char uart_received( unsigned char port );
void uart_send_string(unsigned char port,char *string);
void uart_send_value(unsigned char port,char* caption, int parameter);
void	uart_disable(unsigned char port);

#define UART_RECEIVED_BUFFER_LENGTH 128
char uart_send_buffer[32];
char uart_receive_buffer_0[UART_RECEIVED_BUFFER_LENGTH];
unsigned char uart_receive_buffer_pos[4];

void uart_send_line(unsigned char port,char *string);
void uart_send_int(unsigned char port,int val);
void uart_send_string(unsigned char port,char *string);
void uart_send_float(unsigned char port,float val, char precision);
void uart_add_receive_buffer(unsigned char port, char byte);
char uart_receive_line(unsigned char port);
char uart_wait_line(unsigned char port, int time_ms);
char uart_wait_line_starts_with(unsigned char port, int time_ms, char* stars_with);

#endif /* BWL_UART_H_ */
