name=test
all:main.o
	gcc -g $^ -o $(name) -Iinclude -Llib
%.o:%.c
	gcc -g -c $^ -o $@ -Iinclude -Llib
.PHONY:clean
clean:
	rm $(name) *.o
