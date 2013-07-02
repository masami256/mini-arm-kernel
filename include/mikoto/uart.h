#ifndef __MIKOTO_UART_H
#define __MIKOTO_UART_H

#include <mikoto/char_driver.h>
#include <mikoto/string.h>

#define uart_puts(str) \
		uart_get_driver_instance()->ops->write(str, strlen(str)); 

const struct char_driver *uart_get_driver_instance(void);

#endif // __MIKOTO_UART_H


