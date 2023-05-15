CC = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++17
SANITIZER = -g -fsanitize=address
LINUX_FLAGS = -lrt -lpthread -lm
GCOV_FLAGS ?= --coverage
LIBS = -lgtest
TEST = tests.cc

OS := $(shell uname -s)
USERNAME=$(shell whoami)

ifeq ($(OS),Linux)
  OPEN_CMD=xdg-open
endif
ifeq ($(OS),Darwin)
	OPEN_CMD=open
endif

create_test:
	$(CC) $(CPPFLAGS) $(LIBS) $(TEST) -o test

test: clean create_test
	./test

debug: clean
	$(CC) $(CPPFLAGS) $(LIBS) $(TEST) -o test $(SANITIZER)

leaks: create_test
	leaks -atExit -- ./test

gcov_report: clean
ifeq ($(OS), Darwin)
	$(CC) $(CPPFLAGS) $(GCOV_FLAGS) $(LIBS) $(TEST) -o gcov_report 
else
	$(CC) $(CPPFLAGS) $(GCOV_FLAGS) $(LIBS) $(TEST) -o gcov_report $(LINUX_FLAGS)
endif
	./gcov_report
	lcov -t "stest" -o s21_test.info -c -d ./ --no-external
	genhtml -o report s21_test.info
	$(OPEN_CMD) ./report/index.html

style:
	cp ../materials/linters/.clang-format .
	clang-format -n -style=google *.h *.tpp *.cc
	rm -f .clang-format

clean:
	rm -rf *.out
	rm -rf gcov_report
	rm -rf test
	rm -rf *.info
	rm -rf *.gc*
	rm -rf report
	rm -rf *.dSYM