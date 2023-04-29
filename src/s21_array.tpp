// это можно убрать
#include "s21_array.h"

namespace s21 {
  template <typename T, size_t N>
  Array<T, N>::Array() : begin_(arr_), end_(arr_ + N), size_(N) {}

  
};