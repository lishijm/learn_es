KERNELDIR:=/home/shi/linux-5.4.31
CURRENT_PATH := $(shell pwd)

obj-m:=miscbeep.o

build: kernel_modules

kernel_modules:
	$(MAKE) -C $(KERNELDIR) M=$(CURRENT_PATH) modules
	sudo cp miscbeep.ko /home/shi/projbuildroot/lib/modules/5.4.31
clean:
	$(MAKE) -C $(KERNELDIR) M=$(CURRENT_PATH) clean