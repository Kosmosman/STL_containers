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
  // std::array<int, 2> ar = {1, 2, 3, 4};
  // std::cout << ar[3];
  s21::Array<int, 4> ar = {1, 2, 3};
  std::cout << *ar.begin()  << std::endl;
  // // std::cout << *(ar.end());
  // *ar.begin() = 1423;
  // std::cout << *(ar.begin()) << std::endl;
  // std::cout << *(ar.begin()) << std::endl;
  // int arr[5] = {1, 2, 3, 4, 5};
  // std::cout << *(arr + 5) << std::endl;
}

// что такое вирутальные методы?
// можно ли перезаписывать конструкторы и деструкторы ?
// обязательно ли потомку создавать конструктор и деструктор?
