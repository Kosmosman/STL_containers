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
  // Array<T, N>::Array(const Array<T, N> &a) {
  Array<T, N>::Array(const Array &a) {
    if (a.size_ != N) {
      throw std::out_of_range("Size should be equals");
    }
    // static_assert(std::is_same<T, decltype(a)>::value, "Type mismatch");
    // if (std::is_same<T, decltype(a)>::value, "Type mismatch") {
    //   throw std::out_of_range("Type Error");
    // }
    for (size_type i = 0; i < N; i++) {
      arr_[i] = a.arr_[i];
    }
    begin_ = arr_;
    end_ = arr_ + N;
    size_ = a.size_;
  }


  template <typename T, size_t N>
  Array<T, N>::Array(Array &&a) {
    // нужно ли здесь выкидывать ошибку??
    for (size_type i = 0; i < N; i++) {
      arr_[i] = a.arr_[i];
    }
    begin_ = arr_;
    end_ = arr_ + N;
    size_ = a.size_;

  }

  template <typename T, size_t N>
  Array<T, N>& Array<T, N>::operator=(Array &&a) {
    ~Array(); // нужен ли здесь дестурктор?
    // сделать общую функцию копирования?
    for (size_type i = 0; i < N; i++) {
      arr_[i] = a.arr_[i];
    }
    begin_ = arr_;
    end_ = arr_ + N;
    size_ = a.size_;
  }


  template <typename T, size_t N>
  Array<T, N>::~Array() {
    for (size_t i = 0; i < N; i++) {
      arr_[i] = 0;
    }

    begin_ = nullptr;
    end_ = nullptr;
    size_ = 0;
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

  template <typename T, size_t N>
  void Array<T, N>::swap(Array& other) {
    value_type temp[N];
    for (size_type i = 0; i < N; i++) {
      temp[i] = arr_[i];
    }

    for (size_type i = 0; i < N; i++) {
      arr_[i] = other.arr_[i];
      other.arr_[i] = temp[i];
    }

  }

  template <typename T, size_t N>
  void Array<T, N>::fill(const_reference value) {
    for (size_type i = 0; i < size_; i++) {
      arr_[i] = value;
    }
  }
};

// static_assert(!is_const<_Tp>::value,
          // "cannot swap zero-sized array of type 'const T'");