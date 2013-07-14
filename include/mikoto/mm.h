#ifndef __MIKOTO_MM_H
#define __MIKOTO_MM_H


// defined in paging.h
void paging_init(void);

// Domain control 
void set_domain_access_control(unsigned long data);
unsigned long read_domain_access_control(void);

#endif // __MIKOTO_MM_H


