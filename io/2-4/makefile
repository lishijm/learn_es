CC=gcc
RM=rm -rf
OBJS=secret.o copy.o
CO=*.o
CA=*.a
#将预定以变量添加到工程
export CC RM OBJS CO CA
mf:
	make -C ./src/
	make -C ./obj/
	gcc main.c -Llib -lstate
.PHONY:clean
clean:
	${RM} ./obj/${CO}
	${RM} ./lib/${CA}
	${RM} ./a.out