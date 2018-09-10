CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
DEFINES = -DTEST_INTEGRATE -DRUN_INTEGRATE
PROFFLAG = -pg	
GCC = gcc $(CFLAGS) $(DEFINES) $(COVFLAGS) $(PROFFLAG)
OBJS = pa04.o answer04.o
FUNC = func1.o func2.o func3.o func4.o func5.o
LIBS = -lm

pa04: pa04.h pa04.o answer04.o $(FUNCS)
	$(GCC) pa04.o answer04.o $(FUNCS) -o pa04 -lm

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c


testall: pa04
		./pa04 testdir/test1 output_test1
		./pa04 testdir/test2 output_test2
		./pa04 testdir/test3 output_test3
		./pa04 testdir/test4 output_test4
		./pa04 testdir/test5 output_test5
clean:
	/bin/rm -f input*
	/bin/rm -f *.o
	/bin/rm -f testgen 
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f pa04 pa04.prof
