libmhw.so:softarray.o
	${CC} -shared -fPIC $^ -o $@ 
%.o:%.c
	gcc -fPIC -c $^ -o $@ -I../include 
.PHONY:clean
clean:
	rm  *.o libmhw.so
