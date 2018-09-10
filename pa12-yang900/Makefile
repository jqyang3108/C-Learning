CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wunreachable-code -Wvla -Werror -Wunreachable-code
GCC = gcc $(CFLAGS)

all: pa12.o expressionTree.o scanner.o tree.o
	$(GCC) pa12.o expressionTree.o scanner.o tree.o -o pa12
.c.o: 
	$(GCC) -c $*.c
test1: all
	./pa12 inputs/test1 outputs/test1
test2: all
	./pa12 inputs/test2 outputs/test2
test3: all
	./pa12 inputs/test3 outputs/test3
test4: all
	./pa12 inputs/test4 outputs/test4
testall: all
	./pa12 inputs/test1 outputs/test1 
	./pa12 inputs/test2 outputs/test2
	./pa12 inputs/test3 outputs/test3
	./pa12 inputs/test4 outputs/test4
memory1: all
	valgrind --tool=memcheck --leak-check=full ./pa12 inputs/test1 outputs/test1
memory_all:all
	valgrind --tool=memcheck --leak-check=full ./pa12 inputs/test1 outputs/test1
	valgrind --tool=memcheck --leak-check=full ./pa12 inputs/test2 outputs/test2
	valgrind --tool=memcheck --leak-check=full ./pa12 inputs/test3 outputs/test3
	valgrind --tool=memcheck --leak-check=full ./pa12 inputs/test4 outputs/test4
clean:
	/bin/rm -f *.o
	/bin/rm -f pa12
