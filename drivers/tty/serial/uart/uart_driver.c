#include <mikoto/char_driver.h>
#include <mikoto/uart.h>

static int uart_write(const char *buf, size_t size);

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
uart_get_driver_instance(void)
{
	if (!uart_driver.ops)
		uart_init();

	return &uart_driver;
}

static int 
uart_write(const char *buf, size_t size)
{
	size_t i = 0;

	for (i = 0; i < size; i++) {
		while (*(UART0 + UARTFR) & UARTFR_TXFF)
			;

		*UART0 = buf[i];
	}

	return 0;
}

