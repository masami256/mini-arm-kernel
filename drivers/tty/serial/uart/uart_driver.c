#include <mikoto/uart.h>

void 
puts(const char *s)
{
	while (*s) {
		while (*(UART0 + UARTFR) & UARTFR_TXFF)
			;

		*UART0 = *s;
		s++;
	}
}

