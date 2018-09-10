CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
profflag = -pg
GCC = gcc $(CFLAGS) $(COVFLAGS) $(PROFFLAG)

all: maze.o pa07.o path.o
	$(GCC) maze.o pa07.o path.o -o pa07
.c.o: 
	$(GCC) -c $*.c
test1:all
	echo "Start"
	./pa07 inputs/maze1 inputs/path1
	./pa07 inputs/maze1 inputs/path1-bad1
	./pa07 inputs/maze1 inputs/path1-bad2
	echo "finished"
test2:all
	echo "Start"
	./pa07 inputs/maze2 inputs/path2
	./pa07 inputs/maze2 inputs/path2-bad1
	echo "finished"
test3:all
	echo "Start"
	./pa07 inputs/maze3 inputs/path3
	./pa07 inputs/maze3 inputs/path3-bad1
	echo "finished"
test4:all
	echo "Start"
	./pa07 inputs/maze4 inputs/path4
	./pa07 inputs/maze4 inputs/path4-bad1
	echo "finished"
test5:all
	echo "Start"
	./pa07 inputs/maze5 inputs/path5
	echo "finished"





memory:all
	valgrind --tool=memcheck --leak-check=full ./pa07 inputs/maze1 inputs/path1
clean:
	/bin/rm -f *.o
	/bin/rm -f pa07
