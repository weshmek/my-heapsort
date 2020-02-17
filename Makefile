SOURCES=$(wildcard *.c)
OBJS=${SOURCES:.c=.o}
DEPS=${SOURCES:.c=.d}
CFLAGS=-Werror -Wall


%.d : %.c
	gcc -MM $^ > $@

Test1 : CFLAGS:=${CFLAGS} -Dheap_type=double
Test1 : Heap.o Test1.o
	gcc -o $@ $^ 

Test2 : CFLAGS:=${CFLAGS} -Dheap_type=double
Test2 : Heap.o Test2.o
	gcc -o $@ $^

depend : ${DEPS}

clean :
	rm -f Test1 Test2 ${OBJS} ${DEPS}
	
.PHONY : depend clean

-include ${DEPS}
