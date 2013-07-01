CC = arm-linux-gnu-gcc 
CFLAGS = -mcpu=arm926ej-s -marm -nostdlib --no-builtin -Wall -Werror
CFLAGS += -I$(incdir)

LD = arm-linux-gnu-ld
LDFLAGS = -T mikoto_kernel.ld

