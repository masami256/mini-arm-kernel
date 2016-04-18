CC = arm-none-eabi-gcc
CFLAGS = -mcpu=arm926ej-s -marm -nostdlib --no-builtin -Wall -Werror
CFLAGS += -I$(incdir)

LD = arm-none-eabi-ld
LDFLAGS = -T mikoto_kernel.ld

