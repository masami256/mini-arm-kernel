#ifndef __MIKOTO_PGTABLE_H
#define __MIKOTO_PGTABLE_H
#include <sys/types.h>

#define USE_SMALL_PAGE
#include <mikoto/pgtable_model.h>

int init_pgtable(void);
unsigned long get_translation_table_address(void);

#endif // __MIKOTO_PGTABLE_H

