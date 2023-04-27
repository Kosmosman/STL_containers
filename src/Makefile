CC = g++
FLAGS = -Wall -Werror -Wextra
STLIB = s21_stack.a

.PHONY: all build s21_stack.a test check

all: clean build s21_stack.a test clean

run:
	$(CC) $(FLAGS) main.cc -o main && ./main

build: s21_stack.tpp
	@$(CC) -c $(FLAGS) -std=c++17 s21_stack.tpp -o s21_stack.o

s21_stack.a: build
	@ar rcs $(STLIB) s21_*.o

test:
	@$(CC) $(FLAGS) -lgtest -std=c++17  test/*.cc -o unit_test
	@./unit_test

format:
	@cp ../materials/linters/.clang-format ./
	clang-format -i *.tpp *.cc *.h test/*.cc test/*.h 
	@rm -rf .clang-format

clean:
	rm -rf *.o *.a
	rm -rf unit_test main

check:
	@cp ../materials/linters/.clang-format ./
	clang-format -n *.cpp test/*.cpp test/*.h *.h 
	@rm -rf .clang-format
