CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -Wunreachable-code
GCC = gcc $(CFLAGS) $(TESTS)
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

# This Makefile can be shortened by using loop. 
# It shows all steps to explain what it does

# test integrate1 using five different functions
# each function is tested using three sets of input data

all: pa11

pa11: pa11.o
	$(GCC) pa11.o -o pa11

pa11.o: pa11.c
	$(GCC) -c pa11.c -o pa11.o

test: pa11
	./pa11 inputs/test1
	./pa11 inputs/test2
	./pa11 inputs/test3
	./pa11 inputs/test4
	./pa11 inputs/test5

memory: pa11
	$(VALGRIND) ./pa11 inputs/test1
	$(VALGRIND) ./pa11 inputs/test2
	$(VALGRIND) ./pa11 inputs/test3
	$(VALGRIND) -./pa11 inputs/test4
	$(VALGRIND) -./pa11 inputs/test5

clean:
	/bin/rm -f *.o
	/bin/rm -f pa11 pa11.prof
