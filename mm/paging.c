#include <mikoto/mm.h>
#include <mikoto/register.h>
#include <mikoto/pgtable.h>

static void 
enable_paging(void)
{
	ulong data = 0;
	read_control_register("c1", data);

	// Enable MMU, alignment check, system protection, rom protection, 
	data |= 0x303;
	write_control_register("c1", data);
}

static void 
set_translation_table_address(unsigned long addr)
{
	unsigned long addr = get_translation_table_address() << PAGE_SHIFT;
	write_control_register("c2", addr);
}

void
paging_init(void)
{
	init_pgtable();
}
