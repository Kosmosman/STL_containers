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
  std::array<int, 6> ar = {'1', 2, 3, 4, 5, 6};
  // std::array<int, 5> ar_2= {11, 12, 13, 14, 15};
  // ar_2.fill(5);
  std::cout << ar.front() << std::endl;

  // s21::Array<int, 4> arr_1 = {'f', 2, 3, 4};
  // arr_1.fill(12);
  // std::cout << arr_1.back() << std::endl;

}

// что такое вирутальные методы?
// можно ли перезаписывать конструкторы и деструкторы ?
// обязательно ли потомку создавать конструктор и деструктор?
