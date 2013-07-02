#include <mikoto/uart.h>
#include <mikoto/printf.h>

void
kernel_main(void)
{
	char s[256] = { 0 };
	sprintf(s, "%s\n", "hello, world!");
	uart_puts(s);
	while (1);
}

