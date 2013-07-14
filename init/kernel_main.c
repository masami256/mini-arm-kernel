#include <mikoto/uart.h>
#include <mikoto/printf.h>
#include <mikoto/mm.h>

void
kernel_main(void)
{
	char s[256] = { 0 };
	// setup paging
	paging_init();

	sprintf(s, "%s\n", "hello, world!");
	uart_puts(s);

	while (1);
}

