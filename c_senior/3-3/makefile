CC=gcc
RM=rm -rf
OBJ=App
OBJS=main.o avr.o mark.o age.o nsize.o
*O=*.o
#将预定以变量添加到工程
export CC RM OBJ OBJS
mf:
	make -C ./src/
	make -C ./obj/
.PHONY:clean
clean:
	${RM} ./obj/${*O}
	${RM} ./bin/${OBJ}