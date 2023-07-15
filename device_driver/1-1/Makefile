#KERNELDIR:=/home/shi/fsmp1a-linux-5.4.31
KERNELDIR:=/lib/modules/$(shell uname -r)/build/
PWD:=$(shell pwd)

all:
	make -C $(KERNELDIR) M=$(PWD) modules
clean:
	make -C $(KERNELDIR) M=$(PWD) clean
obj-m:=demo.o