#ifndef __MIKOTO_PRINTF_H
#define __MIKOTO_PRINTF_H

#include <mikoto/stdarg.h>

int sprintf(char *buf, const char *format, ...) __attribute__((format(printf, 2, 3)));

#endif // __MIKOTO_PRINTF_H

