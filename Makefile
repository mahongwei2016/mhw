name=test
all:1.o
	gcc -g $^ -o $(name)
%.o:%.c
	gcc -g -c $^ -o $@
.PHONY:clean
clean:
	rm $(name) *.o
