CC = g++
FLAGS = -Wall -Werror -Wextra
STLIB = s21_stack.a

.PHONY: all build s21_stack.a test check

all: clean build s21_stack.a test clean

run:
	$(CC) $(FLAGS) main.cc -o main && ./main

build: s21_stack.cpp
	@$(CC) -c $(FLAGS) -std=c++17 s21_stack.cpp -o s21_stack.o

s21_stack.a: build
	@ar rcs $(STLIB) s21_*.o

test: $(STLIB)
	@$(CC) $(FLAGS) -lgtest -std=c++17 $(STLIB) test/*.cpp -o unit_test
	@./unit_test

clean:
	rm -rf *.o *.a
	rm -rf unit_test main

check:
	@cp ../materials/linters/.clang-format ./
	clang-format -n *.cpp test/*.cpp *.h 
	@rm -rf .clang-format
