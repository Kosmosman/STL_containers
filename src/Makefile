CC = g++
FLAGS = -Wall -Werror -Wextra
STLIB = s21_stack.a

ifeq ($(OS),Linux)
TEST_LIBS = -lcheck -lm -lpthread -lrt -lsubunit -fprofile-arcs -ftest-coverage
else
TEST_LIBS = -lcheck -lm -lpthread -fprofile-arcs -ftest-coverage
endif


.PHONY: all build s21_stack.a test check

all: clean build s21_stack.a test clean

run:
	$(CC) $(FLAGS) -std=c++17 main.cc -o main && ./main

# s21_stack.o:
# 	$(CC) $(FLAGS) -c 

build: s21_stack.tpp
	@$(CC) $(FLAGS) -std=c++17 s21_stack.tpp -o s21_stack.o

$(STLIB): build
	@ar -crs $(STLIB) s21_*.o

test:
	@$(CC) $(FLAGS) -lgtest -std=c++17 test/*.cc  -o unit_test
	@./unit_test

format:
	@cp ../materials/linters/.clang-format ./
	clang-format -i *.tpp *.cc *.h test/*.cc test/*.h 
	@rm -rf .clang-format

gcov_report: clean 
	$(CC) $(FLAGS) -lgtest -std=c++17 test/*.cc $(TEST_LIBS) -o unit_test
	./unit_test
	lcov -t "./unit_test"  -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html


clean:
	rm -rf *.o *.a *.gcda *.gcno *.info
	rm -rf unit_test main

check:
	@cp ../materials/linters/.clang-format ./
	clang-format -n *.cpp test/*.cpp test/*.h *.h 
	@rm -rf .clang-format
