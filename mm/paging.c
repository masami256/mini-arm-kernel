#include <mikoto/mm.h>
#include <mikoto/register.h>
#include <mikoto/pgtable.h>
#include <mikoto/register.h>
#include <mikoto/uart.h>

static void 
enable_paging(void)
{
	ulong data = 0;
	uart_puts("[-]Start enable_pagin()\n");
	read_control_register_c1(data);

	// Enable MMU, alignment check, system protection, rom protection, 
	data |= 0x303;
	write_control_register_c1(data);
	uart_puts("[-]End enable_pagin()\n");
}

static void 
set_translation_table_address(unsigned long addr)
{
	uart_puts("[-]Start set_translation_table_address()\n");
	unsigned long tmp = addr << PAGE_SHIFT;
	write_control_register_c2(tmp);
	uart_puts("[-]End set_translation_table_address()\n");
}

void
paging_init(void)
{
	uart_puts("[-]Start paging_init()\n");
	init_pgtable();
	set_translation_table_address(get_translation_table_address());
	enable_paging();
	uart_puts("[-]End paging_init()\n");

}
