CC=gcc
RM=rm -rf
OBJ=App
OBJS=main.o outlist.o insert.o
export CC RM OBJ OBJS

mf:
	make -C ./src/
	make -C ./obj/

.PHONY:clean
clean:
	${RM} ./obj/*.o
	${RM} ./bin/${OBJ}