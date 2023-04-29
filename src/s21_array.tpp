// это можно убрать
#include "s21_array.h"

namespace s21 {
  template <typename T, size_t N>
  Array<T, N>::Array() : begin_(arr_), end_(arr_ + N), size_(N) {}

  template <typename T, size_t N>
  Array<T, N>::Array(std::initializer_list<value_type> const &items) : begin_(arr_), end_(arr_ + N), size_(N) {
      if (items.size() > N) {
        throw std::out_of_range("too many initializers for Array");
      }

      int i = 0;
      for (auto it = items.begin(); it != items.end(); it++) {
          arr_[i] = *it;
          i++;
      }
      // заполнение нулями оставшейся части
      for (int j = N - 1; j <= i; j++) {
        arr_[j] = 0;
      }
  }

  template <typename T, size_t N>
  typename Array<T, N>::reference Array<T, N>::operator[](size_type pos) { return arr_[pos]; }

  // template <typename T, size_t N>
  // typename Array<T, N>::reference Array<T, N>::back() {return *end_; }


  template <typename T, size_t N>
  typename Array<T, N>::iterator Array<T, N>::begin() {return begin_; }

  template <typename T, size_t N>
  typename Array<T, N>::iterator Array<T, N>::end() {return end_; }

  template <typename T, size_t N>
  typename Array<T, N>::iterator Array<T, N>::data() {return end_; }

  template <typename T, size_t N>
  typename Array<T, N>::reference Array<T, N>::at(size_type pos) {
      if (pos >= size_) {
        throw std::out_of_range("Index out of range");
      }

      return arr_[pos];
  }
};