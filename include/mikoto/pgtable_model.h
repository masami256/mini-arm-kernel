#ifndef __MIKOTO_PGTABLE_MODEL_H
#define __MIKOTO_PGTABLE_MODEL_H

#define NUM_TRANSLATION_TABLE_ENTRIES 4096
typedef struct translation_table {
    unsigned long index[sizeof(unsigned long) * NUM_TRANSLATION_TABLE_ENTRIES];
} translation_tbl_t;

#define TRANSLATION_TABLE_ADDRESS_ALIGN 0x4000

#ifdef USE_SMALL_PAGE

// Small page uses 4k page.
#define PAGE_SIZE 4096
#define PAGE_SIZE_MASK 0xfffff000

// First level desciriptor
typedef struct first_level_descriptor {
	unsigned page_table_model:2;	// page table model. bit0:1
	unsigned unused_bits_1:2;		// should be 0. bit2:3
	unsigned unused_bits_2:1;		// should be 1. bit:4
	unsigned domain_control:4;  	// Domain control bits. bit5:8
	unsigned unused_bits_3:3;		// should be 0. bit9:11
	unsigned address:20;			// address. bit12:31
} first_lever_descriptor_t __attribute__ ((packed));

// Second level descriptor
typedef struct second_level_descriptor {
	unsigned page_table_model:2;	// page table modesl. bit0:1
	unsigned cache_mode:2;			// cache mode write-back or write-through. bit2:3
	unsigned domain_cotrol_1:2;		// Domain control bit. bit4:5
	unsigned domain_cotrol_2:2;		// Domain control bit. bit6:7
	unsigned domain_cotrol_3:2;		// Domain control bit. bit8:9
	unsigned domain_cotrol_4:2;		// Domain control bit. bit10:11
	unsigned address:20;			// address. bit12:31
} second_level_descriptor_t __attribute__ ((packed));

#define NUM_SMALL_PAGE_FINE_TABLE_ENTRIES 1024
typedef struct first_page_table {
    first_level_descriptor_t desc[sizeof(unsigned long) * NUM_SMALL_PAGE_FINE_TABLE_ENTRIES];
} first_page_tbl_t; 

#define NUM_SMALLE_PAGE_SMALL_PAGE_ENTRIES 1024
typedef struct second_page_table {
    second_level_descriptor_t desc[sizeof(unsigned long) * NUM_SMALLE_PAGE_SMALL_PAGE_ENTRIES];
} second_page_tbl_t;

#else // !USE_SMALL_PAGE
typedef struct first_level_descriptor {
	unsigned long data;
} first_lever_descriptor_t;

typedef struct second_level_descriptor {
	unsigned long data;
} second_level_descriptor_t;

typedef struct first_page_table {
	first_level_descriptor_t desc[1];
} first_page_tbl_t;

typedef struct second_page_table {
	second_level_descriptor_t desc[1];
} second_page_tbl_t;


#endif // USE_SMALL_PAGE

// Page model define.
// http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.ddi0198e/I1039326.html
#define PAGE_MODEL_INVALID 0x0		// generate page fault
#define PAGE_MODEL_LARGE_PAGE 0x1	// Large page model
#define PAGE_MODEL_SMALL_PAGE 0x02  // Small page model
#define PAGE_MODEK_TINY_PAGE 0x03	// Tiny page model

// Cache model define.
// http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.ddi0198e/I1039326.html
#define PGTABLE_CACHE_NOT_USE_CACHE 0x0 // Noncacheable, nonbufferable
#define PGTABLE_CACHE_NO_CACHE_BUFFERABLE 0x1 // Noncacheable, bufferable
#define PGTABLE_CACHE_WRITE_THROUGH 0x2 // Write through cache
#define PGTABLE_CACHE_WRITE_BACK 0x3	// Write back cache

// Domain access control
// http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.ddi0198e/I1039326.html
#define DOMAIN_ACCESS_CTRL_NO_ACCESS 0x0
#define DOMAIN_ACCESS_CTRL_CLIENT 0x1
#define DOMAIN_ACCESS_CTRL_RESERVED 0x2
#define DOMAIN_ACCESS_CTRL_MANAGER 0x03

// Access Permissino
// http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.ddi0198e/I1039326.html
#define ACCESS_PERMISSION_0 0x0
#define ACCESS_PERMISSION_1 0x1
#define ACCESS_PERMISSION_2 0x2
#define ACCESS_PERMISSION_3 0x3


#endif // __MIKOTO_PGTABLE_MODEL_H


