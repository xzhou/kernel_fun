obj-m := module2.o
KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)
default:
		$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

install:
		$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules_install