// #include <iostream>
#include <Stack>
#include <iostream>
#include <ostream>
#include <queue>

// #include "s21_queue.h"
// #include "s21_stack.h"
#include "s21_array.h"
#include <array>

int main() {
  std::stack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.emplace({4, 5});
  std::cout << stack.top() << std::endl;
  // std::array<int, 6> ar = {1, 2, 3, 4, 5, 6};
  // ar.at(0) = 33;
  // std::cout << ar[0] << std::endl;
  // for (auto i : ar) {
  //   std::cout << i << std::endl;
  // }
  // std::array<int, 6> ar_2 = std::move(ar);
  // ar_2.fill(5);
  // s21::Array<int, 6> ar = {'1', 2, 3, 4, 5, 6};
  // s21::Array<char, 6> ar_2 = std::move(ar);
  // std::cout << ar_2.front() << std::endl;

  // s21::Array<int, 4> arr_1 = {'f', 2, 3, 4};
  // arr_1.fill(12);
  // std::cout << arr_1.back() << std::endl;
  return 0;

}

// что такое вирутальные методы?
// можно ли перезаписывать конструкторы и деструкторы ?
// обязательно ли потомку создавать конструктор и деструктор?


