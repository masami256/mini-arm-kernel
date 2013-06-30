CC = arm-linux-gnu-gcc 
CFLAGS= -mcpu=arm926ej-s -marm -nostdlib --no-builtin -Wall

LD = arm-linux-gnu-ld
LDFLAGS = -T mikoto_kernel.ld

