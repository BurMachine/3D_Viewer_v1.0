SRC = translator.c

MAIN = main.c
OBJ		=	$(SRC:%.c=%.o)

CC 		= gcc -std=c11

CFLAGS	= -Wall -Wextra -Werror


all: test

test: 
	@make clean
	@gcc -g $(CFLAGS) $(MAIN) $(SRC) && ./a.out
	@make clean

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

