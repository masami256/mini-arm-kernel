#include <mikoto/char_driver.h>
#include <mikoto/uart.h>

static int uart_write(const char *s);

static struct char_driver_operations uart_ops = {
	.write = uart_write,
};

static struct char_driver uart_driver = {
	.name = "UART",
};

static void 
uart_init(void)
{
	uart_driver.ops = &uart_ops;
}

struct char_driver *
get_uart_driver_instance(void)
{
	if (!uart_driver.ops)
		uart_init();

	return &uart_driver;
}

static int 
uart_write(const char *s)
{
	while (*s) {
		while (*(UART0 + UARTFR) & UARTFR_TXFF)
			;

		*UART0 = *s;
		s++;
	}
	return 0;
}

