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
  // std::array<int, 6> ar = {1, 2, 3, 4, 5};
  // std::array<int, 5> ar_2= {11, 12, 13, 14, 15};
  // ar_2.swap(ar);
  // std::cout << ar_2.back() << std::endl;
  // int a = 3;
  // int arr[14];
  s21::Array<int, 4> arr_1 = {1, 2, 3, 4};
  s21::Array<int, 4> arr_2 = {11, 12, 13, 14};
  arr_2.swap(arr_1);
  std::cout << arr_2.back() << std::endl;
  // ar.fr
  // std::cout << ar.front()  << std::endl;
}

// что такое вирутальные методы?
// можно ли перезаписывать конструкторы и деструкторы ?
// обязательно ли потомку создавать конструктор и деструктор?
