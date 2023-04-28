// #include <iostream>
// #include <Stack>
#include <iostream>
#include <ostream>
#include <queue>

#include "s21_queue.h"
#include "s21_stack.h"

int main() {
  // s21::Queue<int> q = {1, 2, 3};
  // s21::Queue<int> q_2(q);
  // q_2.pop();
  // std::cout << q_2.front() << std::endl;
  // std::cout << q_2.back() << std::endl;
  std::queue<int> original;
  original.push(40);
  std::cout << original.size();

  return 0;
}

// что такое вирутальные методы?
// можно ли перезаписывать конструкторы и деструкторы ?
// обязательно ли потомку создавать конструктор и деструктор?
