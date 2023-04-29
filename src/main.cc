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
  // std::array<int, 5> ar = {1, 2, 3, 4};
  // std::cout << ar.at(40);
  s21::Array<int, 4> ar = {1, 2, 3};
  std::cout << ar.at(-1)  << std::endl;
}

// что такое вирутальные методы?
// можно ли перезаписывать конструкторы и деструкторы ?
// обязательно ли потомку создавать конструктор и деструктор?
