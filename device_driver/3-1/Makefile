ARCH?=

ifeq ($(ARCH),arm)
KERNELDIR:=/home/shi/fsmp1a-linux-5.4.31
else
KERNELDIR:=/lib/modules/$(shell uname -r)/build/
endif
PWD:=$(shell pwd)

NAME?=demo

all:
	make -C $(KERNELDIR) M=$(PWD) modules
	$(CC) -o test test.c
clean:
	make -C $(KERNELDIR) M=$(PWD) clean
	rm test
cp:
	cp demo.ko test /home/shi/_install
obj-m:=$(NAME).o