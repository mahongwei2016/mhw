name=test
all:main.o
	gcc -g $^ -o $(name)
%.o:%.c
	gcc -g -c $^ -o $@
.PHONY:clean
clean:
	rm $(name) *.o
