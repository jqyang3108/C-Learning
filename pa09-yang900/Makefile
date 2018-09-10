CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
PROFFLAG = -pg
GCC = gcc $(CFLAGS) $(COVFLAGS) $(PROFFLAG)
OBJS = pa09.o linkedlist.o answer09.o

all: pa09

pa09: $(OBJS)
	$(GCC) $(OBJS) -o pa09

pa09.o : pa09.c linkedlist.h answer09.h
	$(GCC) -c pa09.c -o pa09.o

answer09.o: answer09.c answer09.h
	$(GCC) -c answer09.c

linkedlist.o: linkedlist.c linkedlist.h
	$(GCC) -c linkedlist.c



clean:
		/bin/rm -f *.o
		/bin/rm -f *.gcno gmon.out *gcov
		/bin/rm -f *.gcda
		/bin/rm -f pa09 pa09.prof
