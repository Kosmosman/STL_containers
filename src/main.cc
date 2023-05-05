// #include <iostream>
#include <Stack>
#include <iostream>
#include <ostream>
#include <queue>

// #include "s21_queue.h"
#include "s21_stack.h"
#include "s21_array.h"
#include <array>

class Example {
  public:
    Example() : x_(0), y_ (0) {};
    Example(int x, int y): x_(x), y_(y) {};
    int getX() { return x_; }
    int getY() { return y_; }
  private:
    int x_, y_;
};


int main() {
  // std::stack<Example> stack_1;
  // stack_1.push(Example(1, 2));
  // stack_1.emplace('ad');
  // std::cout << stack_1.top().getX() << std::endl;

  s21::Stack<Example> stack_2;
  stack_2.push(Example(1, 2));
  stack_2.emplace_front('da');
  std::cout << stack_2.top().getX() << std::endl;

  return 0;

}

// что такое вирутальные методы?
// можно ли перезаписывать конструкторы и деструкторы ?
// обязательно ли потомку создавать конструктор и деструктор?


