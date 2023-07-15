GCC=gcc
RM=rm -rf
BIN=client
OBJ=main.o function.o img.o
O=*.o
export GCC RM BIN OBJ O 
mf:
	make -C ./src/
	make -C ./obj/
.PHONY:clean
clean:
	${RM} ./obj/${O}
	${RM} ./${BIN}