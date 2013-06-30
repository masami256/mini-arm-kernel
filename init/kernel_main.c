#define UART0 ((volatile unsigned int *) 0x101f1000)
#define UARTFR 0x06
#define UARTFR_TXFF 0x20

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

void
kernel_main(void)
{
	puts("hello, world!");
	while (1);
}

