#ifndef __MIKOTO_UART_H
#define __MIKOTO_UART_H

#define UART0 ((volatile unsigned int *) 0x101f1000)
#define UARTFR 0x06
#define UARTFR_TXFF 0x20

void puts(const char *s);

#endif // __MIKOTO_UART_H


