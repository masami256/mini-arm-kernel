include $(topdir)/Makefile.inc

CFLAGS += -I.

objs = kernel_main.o

all: $(objs)

.c.o:
	$(CC) $(CFLAGS) $< -c -o $(objdir)/$*.o

.S.o:
	$(CC) $(CFLAGS) $< -c -o $(objdir)/$*.o

clean:
	find . -name '*~' -exec rm {} \; 

.PHONY: clean all
