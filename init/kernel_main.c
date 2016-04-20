#include <mikoto/uart.h>
#include <mikoto/printf.h>
#include <mikoto/mm.h>

char msg[] = 
"                                   _       _   _                        _ \n"
"                                  (_)     (_) | |                      | |\n"
"   __ _ _ __ _ __ ___    _ __ ___  _ _ __  _  | | _____ _ __ _ __   ___| |\n"
"  / _` | '__| '_ ` _ \\  | '_ ` _ \\| | '_ \\| | | |/ / _ \\ '__| '_ \\ / _ \\ |\n"
" | (_| | |  | | | | | | | | | | | | | | | | | |   <  __/ |  | | | |  __/ |\n"
"  \\__,_|_|  |_| |_| |_| |_| |_| |_|_|_| |_|_| |_|\\_\\___|_|  |_| |_|\\___|_|\n"
"                                                                          \n"
"                                                                          \n";

void kernel_main(void)
{
	char s[256] = { 0 };
	// setup paging
	//paging_init();

	sprintf(s, "%s\n", "hello, world!");
	uart_puts(msg);
	uart_puts("\n");
	uart_puts(s);
	while (1);
}

