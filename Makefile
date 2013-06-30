include Makefile.inc

export objdir = $(shell pwd)/objs

kernel = mikoto_kernel.img

objs = $(shell ls $(odjdir))

subdirs = boot \
		  init

all: setup build 
	$(LD) $(LDFLAGS) $(objdir)/*.o -o $(kernel) 

setup:
	-mkdir $(objdir)

build:
	cd boot && $(MAKE)
	cd init && $(MAKE)

clean:
	-rm -f $(objdir)/*.o 
	find . -name '*~' -exec rm {} \; 

test:
	qemu-system-arm -M versatilepb -nographic -kernel $(kernel)

.PHONY: clean all

