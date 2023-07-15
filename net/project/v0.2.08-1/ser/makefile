GCC=gcc
RM=rm -rf
BIN=service
OBJ=main.o function.o cli_com.o
O=*.o
export GCC RM BIN OBJ O 
mf:
	make -C ./src/
	make -C ./obj/
.PHONY:clean
clean:
	${RM} ./obj/${O}
	${RM} ./${BIN}