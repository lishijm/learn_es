lib:libstate.so
	mv *.so ../lib
libstate.so:${OBJS}
	gcc -shared -fPIC -o libstate.so copy.o secret.o