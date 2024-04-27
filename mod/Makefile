BLDDIR = $(PWD)/../bld
INCDIR = $(PWD)/../inc
KRNDIR = /lib/modules/$(shell uname -r)/build

obj-m += z0_kmod.o
ccflags-y += -I$(INCDIR)

all:
	make -C $(KRNDIR) M=$(PWD) modules

clean:
	make -C $(KRNDIR) M=$(PWD) clean
