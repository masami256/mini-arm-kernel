#ifndef __MIKOTO_CHAR_DRIVER_H
#define __MIKOTO_CHAR_DRIVER_H
#include <sys/types.h>

struct char_driver_operations {
	int (*open)(void);
	int (*close)(void);
	int (*read)(char *buf, size_t size);
	int (*write)(const char *buf);
};

struct char_driver {
	char name[32 + 1];
	struct char_driver_operations *ops;
};

#endif // __MIKOTO_CHAR_DRIVER_H

