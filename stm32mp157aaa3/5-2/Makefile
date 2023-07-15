CROSS_COMPILE = arm-linux-gnueabihf-
NAME = interface
#=============================================================================#
CFLAGS += -g -Wall -O0 -fno-builtin -mabi=apcs-gnu -mfpu=neon -mfloat-abi=softfp \
			-nostdinc -I./common/include    -I./include  		                                       
LD	= $(CROSS_COMPILE)ld
CC	= $(CROSS_COMPILE)gcc
NM  = $(CROSS_COMPILE)nm
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump
#============================================================================#
OBJSss 	:= $(wildcard *.S) \
		   $(wildcard *.c) 
#		   $(wildcard start/*.c) 			   
OBJSs  	:= $(patsubst %.S,%.o,$(OBJSss))
OBJS 	:= $(patsubst %.c,%.o,$(OBJSs))

%.o: %.S 
	@echo "  AS      $@"
	@$(CC) $(CFLAGS) -c -o  $@ $<
%.o: %.c
	@echo "  CC      $@"
	@$(CC) $(CFLAGS) -c -o  $@ $<
all: clean $(OBJS)
	@echo "  LD      Linking $(NAME).elf"
	@$(LD)  $(OBJS) -T map.lds -o $(NAME).elf
	@echo "  OBJCOPY Objcopying $(NAME).bin"
	@$(OBJCOPY)  -O binary  $(NAME).elf $(NAME).bin 
	@echo "  MAP     Generating $(NAME).map"
	@$(NM) $(NAME).elf > $(NAME).map 
	@echo "  OBJDUMP Objdumping $(NAME).dis"
	@$(OBJDUMP) -DS $(NAME).elf > $(NAME).dis 

distclean clean:
	@rm -rf $(OBJS) *.elf *.bin *.dis *.map
	@echo "  CLEAN   complete."

install:
	sudo cp $(NAME).bin /mnt/hgfs/vm_share/
