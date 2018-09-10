CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wunreachable-code -Wvla -Werror -Wunreachable-code
COVFLAGS = 
PROFFLAG = 
GCC = gcc $(CFLAGS) $(COVFLAGS) $(PROFFLAG)


all: pa15.o
	$(GCC) pa15.o -o pa15

.c.o: 
	$(GCC) -c $*.c

testall:all
	./pa15 inputs/basic 1basic_sorted 1basic_huffman 1basic_header
	./pa15 inputs/gophers 2gophers_sorted 2gophers_huffman 2gophers_header
	./pa15 inputs/para 3para_sorted 3para_huffman 3para_header
	./pa15 inputs/woods 4woods_sorted 4woods_huffman 4woods_header
	./pa15 inputs/prideandprejudice 5prideandprejudice_sorted 5prideandprejudice_huffman 5prideandprejudice_header

memory:all

	valgrind --tool=memcheck --leak-check=full ./pa15 inputs/basic 1basic_sorted 1basic_huffman 1basic_header
	valgrind --tool=memcheck --leak-check=full ./pa15 inputs/gophers 2gophers_sorted 2gophers_huffman 2gophers_header
	valgrind --tool=memcheck --leak-check=full ./pa15 inputs/para 3para_sorted 3para_huffman 3para_header
	valgrind --tool=memcheck --leak-check=full ./pa15 inputs/woods 4woods_sorted 4woods_huffman 4woods_header
	valgrind --tool=memcheck --leak-check=full ./pa15 inputs/prideandprejudice 5prideandprejudice_sorted 5prideandprejudice_huffman 5prideandprejudice_header

clean:
	/bin/rm -f *.o
	/bin/rm -f pa15
	/bin/rm -f pa15 1basic_sorted 1basic_huffman 1basic_header
	/bin/rm -f pa15 2gophers_sorted 2gophers_huffman 2gophers_header
	/bin/rm -f pa15 3para_sorted 3para_huffman 3para_header
	/bin/rm -f pa15 4woods_sorted 4woods_huffman 4woods_header
	/bin/rm -f pa15 5prideandprejudice_sorted 5prideandprejudice_huffman 5prideandprejudice_header
