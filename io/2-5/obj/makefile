lib:libstate.so
	mv *.so ../lib
libstate.so:${OBJS}
	gcc -shared -o libstate.so copy.o secret.o