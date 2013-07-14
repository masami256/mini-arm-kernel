#include <mikoto/kernel.h>
#include <mikoto/pgtable.h>

// local functions
static void setup_translation_table(void);

// Use these page setting for initialize the kernel
static void setup_first_pgtable_for_init(void);
static void setup_second_pgtable_for_init(void);

// Translation Table.
// This table shiuld be 16KiB align.
static translation_tbl_t translation_tbl __attribute__((aligned(TRANSLATION_TABLE_ADDRESS_ALIGN))); 

// Temoporay page tables.
static first_page_tbl_t init_first_pgtable = { 0 };
static second_page_tbl_t init_second_pgtable { 0 };

// 1st page table for init

static void
setup_translation_table(void)
{
	translation_tbl[0] = &init_first_pgtable;
}

static inline first_level_descriptor_t
set_first_descriptor_data(int page_model, int domain_control, unsigned long addr)
{
	first_level_descriptor_t data = 0;
	data.page_table_model = page_model;
	data.unused_bits_1 = 0;
	data.unused_bits_2 = 1;
	data.domain_control = domain_control;
	data.unused_bits_3 = 0;
	data.address = addr;

	return data;
}

static void 
setup_first_pgtable_for_init(void)
{
	unsigned long addr = ((unsigned long) &init_second_pgtable) & PAGE_SIZE_MASK;

	init_first_pgtable[0] = set_first_descriptor_data(PAGE_MODEL_SMALL_PAGE,
														DOMAIN_ACCESS_CTRL_MANAGER,
														addr);

}

static inline second_level_descriptor_t
set_second_descriptor_data(int page_model, int cache_mode,
							int domain_control, unsigned long addr)
{
	second_level_descriptor_t desc = 0;
	desc.page_table_model = page_model;
	desc.cache_mode = cache_mode;
	desc.domain_cotrol_1 = domain_control;
	desc.domain_cotrol_2 = domain_control;
	desc.domain_cotrol_3 = domain_control;
	desc.domain_cotrol_4 = domain_control;
	desc.address = addr;
	return desc;
}

static void 
setup_second_pgtable_for_init(void)
{
	int i = 0;
	unsigned long addr = 0;

	for (i = 0; i < NUM_SMALLE_PAGE_SMALL_PAGE_ENTRIES; i++) {
		init_second_pgtable[i] = set_second_descriptor_data(PAGE_MODEL_SMALL_PAGE,
															PGTABLE_CACHE_WRITE_THROUGH,
															ACCESS_PERMISSION_3,
															addr);
		addr += PAGE_SIZE;
	}

}

int
init_pgtable(void)
{
	setup_translation_table();
	setup_first_pgtable_for_init();
	setup_second_pgtable_for_init();

    return 0;
}

unsigned long
get_translation_table_address(void)
{
	return (unsigned long) &translation_tbl;
}

