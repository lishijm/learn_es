OBJ=main.o find.o crlist.o
export OBJ
mf:
	make -C ./src/
	make -C ./obj/
.PHONY:clean
clean:
	rm -rf ./obj/*.o
	rm -rf ./bin/out