#include <mikoto/uart.h>

void
kernel_main(void)
{
	uart_puts("hello, world!");
	while (1);
}

