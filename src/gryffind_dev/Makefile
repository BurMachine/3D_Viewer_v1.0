SRC = afinn_translation.c ./matrix/s21_calc_complements.c ./matrix/s21_create_matrix.c \
./matrix/s21_eq_matrix.c ./matrix/s21_inverse_matrix.c ./matrix/s21_mult.c \
./matrix/s21_remove_matrix.c ./matrix/s21_sum_sub.c ./matrix/s21_transpon.c ./matrix/determinant.c ./matrix/check.c\
         supportFunction.c parsing.c printers.c
SRC_TEST = ./matrix/s21_calc_complements.c ./matrix/s21_create_matrix.c \
./matrix/s21_eq_matrix.c ./matrix/s21_inverse_matrix.c ./matrix/s21_mult.c \
./matrix/s21_remove_matrix.c ./matrix/s21_sum_sub.c ./matrix/s21_transpon.c ./matrix/determinant.c ./matrix/check.c\
         parsing.c printers.c


MAIN = main.c
OBJ		=	$(SRC:%.c=%.o)

CC 		= gcc -std=c11

CFLAGS	= -Wall -Wextra -Werror

TEST = test_by_vadim.c
FLAGS_PLATFORM = -lcheck
GCOVFLAGS = -fprofile-arcs -ftest-coverage
REPORT = GcovReport

all: test

.PHONY: all, install, uninstall,clean, dvi, dist, tests, gcov_report

test: 
	@make clean
	@gcc -g  $(MAIN) $(SRC) && ./a.out
	@make clean
# $(CFLAGS)
clean:
	@rm -rf *.{a,o,dSYM,out}
	@rm -rf $(EXECUTABLE)
	@rm -rf gcov_report
	@rm -rf report
	@rm -rf CPPLINT.cfg
	@rm -rf *.gcda
	@rm -rf *.gcno
	@rm -rf *.info
	@rm -rf test
	@rm -rf Archive_SmartCalc_v1.0 
	@rm -rf *tgz
	@rm -rf build
	@rm -rf gcov_test

tests:
	@$(CC) $(TEST) $(SRC_TEST) $(FLAGS_PLATFORM) -o tests.out
	@./tests.out
dvi:
	open dvi.html

gcov_report:
	gcc $(GCOVFLAGS) $(TEST) $(SRC_TEST) $(FLAGS_PLATFORM) -o $(REPORT)
	chmod +x *
	./GcovReport
	lcov -t "$(REPORT)" -o $(REPORT).info -c -d .
	genhtml -o report $(REPORT).info
	rm -rf ./*.gcno ./*.gcda ./$(REPORT).*
	open ./report/index.html
	rm $(REPORT)
	rm -rf *.dSYM

install:
	make clean
	mkdir ../../build
	cd ../../Viewer2 && qmake && make && make clean && rm Makefile && cd ../ && mv Viewer2/Viewer2.app build
	open ../../build/Viewer2.app/Contents/MacOS/Viewer2
uninstall:
	rm -rf ../../build*
open:
	open ../../build/Viewer2.app/Contents/MacOS/Viewer2

check: $(NAME)
	@echo ---------------------CPPCHECK---------------------
	cppcheck *.h $(SRC)
	@echo ---------------------CPPLINT----------------------
	cp ../../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../../materials/linters/cpplint.py --extension=c $(SRC)/gryffind_dev/* $(TEST) *.h *.c
	rm CPPLINT.cfg

dist:
	rm -rf ../../bistViewer2.bist/
	mkdir ../../bistViewer2.bist/
	mkdir ../../bistViewer2.bist/
	cp ../../build/Contents/MacOS/Viewer2 ../../bistViewer2.bist/
	cd ../.. && tar cvzf bistViewer2.bist.tgz ../../bistViewer2.bist && mv ../bistViewer2.bist
