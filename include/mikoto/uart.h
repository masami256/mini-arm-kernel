#ifndef __MIKOTO_UART_H
#define __MIKOTO_UART_H

#include <mikoto/char_driver.h>
#include <mikoto/string.h>

#define UART0 ((volatile unsigned int *) 0x101f1000)
#define UARTFR 0x06
#define UARTFR_TXFF 0x20

#define uart_puts(str) \
	do { \
		struct char_driver *uart = get_uart_driver_instance(); \
		uart->ops->write(str, strlen(str)); \
	} while(0);

struct char_driver *get_uart_driver_instance(void);

#endif // __MIKOTO_UART_H


