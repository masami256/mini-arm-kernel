#include <mikoto/stdlib.h>
#include <mikoto/printf.h>

#define PRINTK_BUF_SIZE (64 + 1)

static int
copy_buf(char *to, const char *from)
{
	int ret = 0;

	while (*from) {
		*to++ = *from++;
		ret++;
	}
	return ret;
}

/**
 * It's a simple printf(3) for kernel.
 * @param fmt as format strings.
 * @param arguments for format strings.
 */
int
sprintf(char *buf, const char *fmt, ...) 
{
	va_list ap;
	int ival;
	char *sval;
	int ret = 0;

	va_start(ap, fmt);
	while (*fmt) {
		char tmp_buf[PRINTK_BUF_SIZE] = { 0 };
		if (*fmt == '%') {
			switch (*++fmt) {
			case 'd':
			case 'c':
			case 'u':
				ival = va_arg(ap, int);
				itoa(ival, tmp_buf);
				ret += copy_buf(buf + ret, tmp_buf);
				break;
			case 'x':
				ival = va_arg(ap, int);
				itox(ival, tmp_buf);
				ret += copy_buf(buf + ret, tmp_buf);
				break;
			case 's':
				sval = va_arg(ap, char *);
				ret += copy_buf(buf + ret, sval);
				break;
			default:
				break;
			}
			fmt++;
		} else {
			*(buf + ret) = *fmt;
			fmt++;
			ret++;
		}
	}
	va_end(ap);
	return ret;
}

