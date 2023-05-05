// #include <iostream>
#include <Stack>
#include <array>
#include <iostream>
#include <ostream>
#include <queue>

#include "s21_array.h"
#include "s21_queue.h"
#include "s21_stack.h"

class Example {
 public:
  Example() : x_(0), y_(0){};
  Example(int x, int y) : x_(x), y_(y){};
  int getX() { return x_; }
  int getY() { return y_; }

 private:
  int x_, y_;
};

int main() {
  // std::queue<Example> queue_1;
  // queue_1.push(Example(1, 2));
  // queue_1.emplace(4, 5);
  // std::cout << queue_1.back().getX() << std::endl;

  s21::Queue<Example> queue_2;
  queue_2.push(Example(1, 2));
  queue_2.emplace_back(4, 5);
  std::cout << queue_2.back().getX() << std::endl;

  return 0;
}

// что такое вирутальные методы?
// можно ли перезаписывать конструкторы и деструкторы ?
// обязательно ли потомку создавать конструктор и деструктор?
