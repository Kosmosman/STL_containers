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

      size_t i = 0; // кажется можно заменить на items.size()
      for (auto it = items.begin(); it != items.end(); it++) {
          arr_[i] = *it;
          i++;
      }
      // if items.size() < N, fill zero from items.size() ... N
      for (size_t j = i; j < N; j++) {
        arr_[j] = 0;
      }
  }


  template <typename T, size_t N>
  typename Array<T, N>::reference Array<T, N>::operator[](size_type pos) { return arr_[pos]; }

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

  template <typename T, size_t N>
  bool Array<T, N>::empty() { return size_ == 0; }

  template <typename T, size_t N>
  typename Array<T, N>::size_type Array<T, N>::size() { return size_; }

  template <typename T, size_t N>
  typename Array<T, N>::size_type Array<T, N>::max_size() { return size_; }

  template <typename T, size_t N>
  typename Array<T, N>::const_reference Array<T, N>::front() const {
    return *begin_;
  }

  template <typename T, size_t N>
  typename Array<T, N>::reference Array<T, N>::front() {
    return *begin_;
  }

  template <typename T, size_t N>
  typename Array<T, N>::const_reference Array<T, N>::back() const {
    return *(end_ - 1);
  }

  template <typename T, size_t N>
  typename Array<T, N>::reference Array<T, N>::back() {
    return *(end_ - 1);
  }
};