CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
PROFFLAG = -pg
GCC = gcc $(CFLAGS) $(COVFLAGS) $(PROFFLAG)
OBJS = pa08.o solver.o maze.o

all: pa08

pa08: $(OBJS)
	$(GCC) $(OBJS) -o pa08

pa08.o : pa08.c path.h maze.h
	$(GCC) -c pa08.c -o pa08.o

solver.o: solver.c solver.h
	$(GCC) -c solver.c

maze.o: maze.c maze.h
	$(GCC) -c maze.c
	
test1: all
	echo "start"
	./pa08 inputs/maze1
	echo "finished"
	
memory: all
	valgrind --tool=memcheck --leak-check=full ./pa08 inputs/maze1

clean:
		/bin/rm -f *.o
		/bin/rm -f *.gcno gmon.out *gcov
		/bin/rm -f *.gcda
		/bin/rm -f pa08 pa08.prof
