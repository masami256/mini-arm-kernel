include Makefile.inc

export topdir = $(shell pwd)
export objdir = $(shell pwd)/objs
export incdir = $(topdir)/include

kernel = mikoto_kernel.img

objs = $(shell ls $(odjdir))

all: setup build 
	$(LD) $(LDFLAGS) $(objdir)/*.o -o $(kernel) 

setup:
	-mkdir $(objdir)

build:
	cd boot && $(MAKE)
	cd init && $(MAKE)
	cd drivers && $(MAKE)
	cd klibs && $(MAKE)

clean:
	-rm -f $(objdir)/*.o 
	-rm -f $(kernel)
	find . -name '*~' -exec rm {} \; 

test:
	QEMU_AUDIO_DRV=none qemu-system-arm -M versatilepb -nographic -kernel $(kernel) -m 128

.PHONY: clean all

