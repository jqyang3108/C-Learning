CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wunreachable-code -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
PROFFLAG = -pg
OBJECTS = pa10.o solver.o maze.o path.o mazehelper.o list.o
GCC =gcc $(CFLAGS)

pa10: $(OBJECTS)
	$(GCC) $(OBJECTS) -o pa10

.c.o:
	$(GCC) -c $*.c

test: pa10
	./pa10 inputs/maze1 output1
	./pa10 inputs/maze2 output2	
	./pa10 inputs/maze3 output3

memory: pa10
	valgrind --tool=memcheck --track-origins=yes --leak-check=full --show-reachable=yes ./pa10 inputs/maze1 outputs/output1
	valgrind --tool=memcheck --track-origins=yes --leak-check=full --show-reachable=yes ./pa10 inputs/maze2 outputs/output2
	valgrind --tool=memcheck --track-origins=yes --leak-check=full --show-reachable=yes ./pa10 inputs/maze3 outputs/output3

clean:
	/bin/rm -f *.o
	/bin/rm -f *.gcno gmon.out *gcov
	/bin/rm -f *.gcda
