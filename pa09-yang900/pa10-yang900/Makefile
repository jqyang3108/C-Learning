CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wunreachable-code -Wvla -Werror -Wunreachable-code
COVFLAGS = 
PROFFLAG = 
GCC = gcc $(CFLAGS) $(COVFLAGS) $(PROFFLAG)

all: maze.o pa10.o path.o solver.o list.o mazehelper.o
	$(GCC) solver.o maze.o pa10.o path.o list.o mazehelper.o -o pa10
.c.o: 
	$(GCC) -c $*.c

test:all
	./pa10 inputs/maze1 output1
	./pa10 inputs/maze2 output2
	./pa10 inputs/maze3 output3
memory:all
	valgrind --tool=memcheck --leak-check=full ./pa10 inputs/maze1 output1
	valgrind --tool=memcheck --leak-check=full ./pa10 inputs/maze2 output2
	valgrind --tool=memcheck --leak-check=full ./pa10 inputs/maze3 output3
clean:
	/bin/rm -f *.o
	/bin/rm -f pa10