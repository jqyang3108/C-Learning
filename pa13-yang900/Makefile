CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -Wunreachable-code
COVFLAGS = -fprofile-arcs -ftest-coverage
GCC = gcc $(CFLAGS) $(COVFLAGS)

OBJS = pa13.o bmp.o filter.o

pa13: $(OBJS)
	$(GCC) $(OBJS) -o pa13

testall: pa13
	./pa13 test.bmp 

filter.o: filter.c filter.h
	 $(GCC) -c filter.c -o filter.o

bmp.o: bmp.c bmp.h
	$(GCC) -c bmp.c -o bmp.o

pa13.o: pa13.c bmp.h
	$(GCC) -c pa13.c

clean:
	/bin/rm -f *.o
	/bin/rm -f pa13
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
