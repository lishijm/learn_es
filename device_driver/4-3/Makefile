ARCH?=

ifeq ($(ARCH),arm)
KERNELDIR:=/home/shi/fsmp1a-linux-5.4.31
else
KERNELDIR:=/lib/modules/$(shell uname -r)/build/
endif
PWD:=$(shell pwd)

all:
	make -C $(KERNELDIR) M=$(PWD) modules
clean:
	make -C $(KERNELDIR) M=$(PWD) clean
cp:
	cp *.ko /home/shi/_install

obj-m = vbus.o vdev.o vdrv.o