# You need to write this file so that
#
# "make" will create an executable called pa06
# 
# "make test" will run the three input files 
# 
# input: inputs/testinput1; output: id1, first1, last1
# input: inputs/testinput2; output: id2, first2, last2
# input: inputs/testinput3; output: id3, first3, last3
# 
# compare your program's output with the expected ouputs by
# using the "diff" command in Linux
#
# "make memory" calls valgrind to check memory errors
#
# "make clean" remove .o and all output files

CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
TESTFLAG = -DTEST_READ -DTEST_WRITE -DTEST_SORTID -DTEST_SORTFIRSTNAME -DTEST_SORTLASTNAME
GCC = gcc $(CFLAGS) $(COVFLAGS)


pa06: pa06.o student.o
	$(GCC) pa06.o student.o -o pa06

pa06.o: pa06.c student.h constant.h
	$(GCC) -c pa06.c -o pa06.o

student.o: student.c msort.c msort.h student.h
	$(GCC) $(TESTFLAG) -c student.c msort.c -o student.o

test:pa06
	./pa06 inputs/testinput1 id1 first1 last1
	./pa06 inputs/testinput2 id2 first2 last2
	./pa06 inputs/testinput3 id3 first2 last3

	diff id1 expected/id1
	diff first1 expected/first1
	diff last1 expected/last1

	diff id2 expected/id2
	diff first2 expected/first2
	diff last2 expected/last2

	diff id3 expected/id3
	diff first3 expected/first3
	diff last3 expected/last3
memory: pa06
	valgrind --leak-check=full ./pa06 inputs/testinput1 id1 first1 last1
	valgrind --leak-check=full ./pa06 inputs/testinput2 id2 first2 last2
	valgrind --leak-check=full ./pa06 inputs/testinput3 id3 first3 last3

clean:	
	/bin/rm -f *.o
	/bin/rm -f *.gcno gmon.out *gcov
	/bin/rm -f pa06 pa06.prof
	/bin/rm -f *.gcda
	/bin/rm -f *id1 id2 id3 first1 first2 first3 last1 last2 last3


