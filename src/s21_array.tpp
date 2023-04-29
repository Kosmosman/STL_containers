// это можно убрать
#include "s21_array.h"

namespace s21 {
  template <typename T, size_t N>
  Array<T, N>::Array() : begin_(arr_), end_(arr_ + N), size_(N) {}

  template <typename T, size_t N>
  Array<T, N>::Array(std::initializer_list<value_type> const &items) {
      int i = 0;
      for (auto it = items.begin(); it != items.end(); it++) {
          arr_[i] = *it;
          i++;
      }
      begin_ = arr_;
      end_ = arr_ + N;
      size_ = N;
  }
  template <typename T, size_t N>
  reference Array<T, N>::operator[](size_type pos)
};