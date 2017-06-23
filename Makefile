name=test
all:main.o
	make -C ./lib
	gcc -g  -o $(name) $^ -I${PWD}/include -L${PWD}/lib -lmhw
%.o:%.c
	gcc -g -c $^ -o $@ -Iinclude
.PHONY:clean
clean:
	make -C lib clean
	rm $(name) *.o
