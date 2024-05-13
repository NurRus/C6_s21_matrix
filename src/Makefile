OS = $(shell uname)
CFLAGS = -Wall -Werror -Wextra -g -std=c11

ALL_FUNC = $(wildcard ./*.c)

SOURCE_TESTS_FUNC = $(wildcard ./tests/*.c)

ifeq ($(OS), Darwin)
	det_OS = -lcheck
	GCOV_FLAGS = -fprofile-arcs -ftest-coverage
else
	det_OS = -lcheck -lsubunit -lm -pthread -lrt
endif

all: clean s21_matrix.a 

test: clean s21_matrix.a
	gcc $(CFLAGS) $(ALL_FUNC) $(SOURCE_TESTS_FUNC) --coverage s21_matrix.a -o s21_test_matrix $(det_OS)
	./s21_test_matrix

s21_matrix.a:
	gcc $(CFLAGS) $(ALL_FUNC) $(GCOV_FLAGS) -c
	ar rc s21_matrix.a *.o
	ranlib s21_matrix.a

gcov_report: clean s21_matrix.a test
	@lcov -t "s21_test_matrix" -o test.info --no-external -c -d .
	@genhtml -o report test.info
	open report/index.html
	rm -rf *.gcno *gcda *.gco

clean:
	rm -rf test *.gcda *.gcno *.o *.info *.a *.h.gch tests/*.gcno report 
	rm -rf s21_test_matrix.dSYM s21_test_matrix
	rm -rf tests/*.h.gch 

style:
	clang-format -n -style=google *.h $(ALL_FUNC) $(SOURCE_TESTS_FUNC)
	@rm -rf .clang-format

style_repair:
	@cp ../materials/linters/.clang-format ../src  
	@clang-format -i -style=google *.h $(ALL_FUNC) $(SOURCE_TESTS_FUNC)

leaks:
	leaks -atExit -- ./s21_test_matrix

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov
