// #include <iostream>
// #include <Stack>
#include <iostream>
#include <ostream>

#include "s21_queue.h"
#include "s21_stack.h"

int main() {
  s21::Queue<int> q = {1, 2, 3};
  //   q.push(4);
  std::cout << q.front() << std::endl;
  std::cout << q.back() << std::endl;

  //   q.push(5);
  //   std::cout << q.front() << std::endl;
  //   std::cout << q.back() << std::endl;

  //   q.push(6);
  //   std::cout << q.front() << std::endl;
  //   std::cout << q.back() << std::endl;

  return 0;
}

// что такое вирутальные методы?
// можно ли перезаписывать конструкторы и деструкторы ?
// обязательно ли потомку создавать конструктор и деструктор?
