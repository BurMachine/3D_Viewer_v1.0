CC=gcc
CFLAGS= -std=c11 -Wall -Werror -Wextra
GCOVFLAGS=-fprofile-arcs -ftest-coverage
LFLAGS= --coverage
CHECKFLAGS=$(shell pkg-config --libs check) #-lcheck -lm -lpthread -lrt -lsubunit
DEBUGFLG= -g -fsanitize=leak
SRC=s21_matrix.c
OBJ=s21_matrix.o
LIB=s21_matrix.a
OBJ_TARG=test_matrix
TARGET=/

.PHONY: help all clean test s21_matrix.a gcov_report

help:
	@echo "Available targets:"
	@echo "  make test"
	@echo "  make s21_matrix.a"
	@echo "  make gcov_report"



clean:
	rm -rf s21_matrix_test test/s21_test_matrix s21_test_matrix test/*.gcda test/*.o test/*.gcno *.gch *.gcda *.gcno *.a *.o *.json coverage.* *.info ./report/ ./s21_matrix_test.dSYM/
all:	build

build: $(LIB)

rebuild: clean build

s21_test_matrix.o: 
	$(CC) $(CFLAGS) -c -g test/s21_test_matrix.c -o test/s21_test_matrix.o

test: clean s21_test_matrix.o s21_matrix.a 
	$(CC) $(CFLAGS) -o test/s21_test_matrix test/s21_test_matrix.o -L. -ls21_matrix $(CHECKFLAGS)
#	leaks -atExit -- ./test/s21_test_matrix
	valgrind  --tool=memcheck --track-origins=yes --leak-check=yes  ./test/s21_test_matrix #--log-file="log.txt"
	./test/s21_test_matrix

s21_matrix.a: *.c s21_matrix.h
	$(CC) $(CFLAGS) -c -g *.c
	ar -rc libs21_matrix.a *.o
	ranlib libs21_matrix.a
	cp libs21_matrix.a s21_matrix.a

gcov_lib:	*.c s21_matrix.h
	$(CC) $(CFLAGS) $(GCOVFLAGS) $(LFLAGS) -c *.c
	ar -rc libs21_matrix.a *.o
	ranlib libs21_matrix.a

gcov_test:	gcov_lib #s21_decimal_test.check 
#	checkmk ./s21_decimal_test.check >s21_decimal_test.c
	$(CC) $(CFLAGS) $(GCOVFLAGS) -c test/s21_test_matrix.c -o test/s21_test_matrix.o
	$(CC) $(CFLAGS) $(GCOVFLAGS) $(LFLAGS) test/s21_test_matrix.o -L./ -ls21_matrix $(CHECKFLAGS) -o s21_test_matrix


gcov_report:	clean gcov_lib gcov_test
	./s21_test_matrix
#	valgrind --tool=memcheck --leak-check=yes ./s21_decimal_test
	lcov -t "s21_test_matrix" -o s21_test_matrix.info -c -d .
	genhtml -o report s21_test_matrix.info
#	gcovr --html-details coverage.html
