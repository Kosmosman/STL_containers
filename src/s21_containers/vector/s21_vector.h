#ifndef SRC_S21_CONTAINERS_VECTOR_S21_VECTOR_H_
#define SRC_S21_CONTAINERS_VECTOR_S21_VECTOR_H_

#include <cmath>
#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename T>
class VectorIterator;

template <typename T>
class VectorConstIterator;

template <typename T>
class Vector {
 public:
  // Vector Member type
  using value_type = T;
  using reference_type = T&;
  using const_reference = const T&;
  using iterator = VectorIterator<T>;
  using const_iterator = VectorConstIterator<T>;
  using size_type = std::size_t;

  //  Vector Member functions
  Vector() : size_(0), capacity_(0), data_(nullptr){};

  explicit Vector(size_type n) {
    if (n > max_size()) {
      throw std::length_error(
          "Can't create s21::Vector larger than max_size()");
    }
    size_ = n;
    capacity_ = n;
    data_ = new value_type[capacity_];
  };

  Vector(std::initializer_list<value_type> const& items)
      : size_(items.size()),
        capacity_(items.size()),
        data_(new value_type[capacity_]) {
    std::copy(items.begin(), items.end(), data_);
  }

  Vector(const Vector& v)
      : size_(v.size_),
        capacity_(v.capacity_),
        data_(new value_type[capacity_]) {
    for (size_type i = 0; i < size_; i++) {
      data_[i] = v.data_[i];
    }
  }

  Vector(Vector&& v) : size_(v.size_), capacity_(v.capacity_), data_(v.data_) {
    v.bring_to_zero();
  }

  ~Vector() { remove(); }

  Vector& operator=(const Vector& v) {
    if (this != &v) {
      remove();
      size_ = v.size_;
      capacity_ = v.capacity_;
      data_ = new value_type[capacity_];
      for (size_type i = 0; i < size_; i++) {
        data_[i] = v.data_[i];
      }
    }
    return *this;
  }

  Vector& operator=(Vector&& v) {
    if (this != &v) {
      remove();
      size_ = v.size_;
      capacity_ = v.capacity_;
      data_ = v.data_;
      v.bring_to_zero();
    }
    return *this;
  }

  // Vector Element access
  reference_type at(size_type pos) {
    if (pos >= size()) {
      throw std::out_of_range("Index is out of range");
    }
    return data_[pos];
  }

  reference_type operator[](size_type pos) { return data_[pos]; }

  const_reference front() { return *data_; }

  const_reference back() { return *(data_ + size_ - 1); }

  iterator data() { return data_; }

  // Vector Iterators
  iterator begin() { return iterator(data_); }

  iterator end() { return iterator(data_ + size_); }

  // Vector Capacity
  bool empty() { return (size_ == 0); }

  size_type size() { return size_; }

  size_type max_size() {
    int bits = 63;
    if (sizeof(void*) == 4) {
      bits = 31;
    }
    return static_cast<size_type>(pow(2, bits)) / sizeof(value_type) - 1;
  }

  void reserve(size_type size) {
    if (size > max_size()) {
      throw std::length_error("Size is too large");
    }
    if (size > size_) {
      allocate(size);
    }
  }

  size_type capacity() { return capacity_; }

  void shrink_to_fit() {
    if (size_ < capacity_) {
      allocate(size_);
    }
  }

  // Vector Modifiers
  void clear() { size_ = 0; }

  iterator insert(iterator pos, const_reference value) {
    size_type position = &(*pos) - data_;
    size_type zero = 0;
    if (position < zero || position > size_) {
      throw std::out_of_range("Index is out ot range");
    }
    if (size_ + 1 >= capacity_) {
      allocate(size_ * 2);
    }
    value_type replace = data_[position];
    size_++;
    data_[position] = value;
    for (size_type i = position + 1; i < size_; ++i) {
      value_type next = data_[i];
      data_[i] = replace;
      replace = next;
    }
    return data_ + position;
  }

  void erase(iterator pos) {
    size_type position = &(*pos) - data_;
    size_type zero = 0;
    if (position < zero || position > size_) {
      throw std::out_of_range("Index is out ot range");
    }
    for (size_type i = position + 1; i < size_; i++) {
      data_[i - 1] = data_[i];
    }
    size_--;
  }

  void push_back(const_reference value) {
    if (size_ >= capacity_) {
      if (!size_) {
        allocate(1);
      } else {
        allocate(size_ * 2);
      }
    }
    data_[size_++] = value;
  }

  void pop_back() {
    if (size_ > 0) {
      size_--;
    }
  }

  void swap(Vector& other) {
    using std::swap;
    swap(size_, other.size_);
    swap(capacity_, other.capacity_);
    swap(data_, other.data_);
  }

 private:
  size_type size_;
  size_type capacity_;
  value_type* data_;

  void allocate(size_type new_cap) {
    value_type* new_data = new value_type[new_cap];
    for (size_type i = 0; i < size_; ++i) {
      new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = new_cap;
  }

  void bring_to_zero() {
    size_ = 0;
    capacity_ = 0;
    data_ = nullptr;
  }

  void remove() {
    delete[] this->data_;
    bring_to_zero();
  }
};

template <typename T>
class VectorIterator {
  friend class Vector<T>;
  friend class VectorConstIterator<T>;

 public:
  using value_type = T;
  using pointer_type = T*;
  using reference_type = T&;

  VectorIterator() : ptr_(){};
  VectorIterator(pointer_type ptr) : ptr_(ptr) {}

  VectorIterator& operator++() {
    ptr_++;
    return *this;
  }
  VectorIterator operator++(int) {
    VectorIterator tmp = *this;
    ++(*this);
    return tmp;
  }
  VectorIterator& operator--() {
    ptr_--;
    return *this;
  }
  VectorIterator operator--(int) {
    VectorIterator tmp = *this;
    --(*this);
    return tmp;
  }
  VectorIterator operator+(const size_t value) {
    VectorIterator tmp(this->ptr_ + value);
    return tmp;
  }
  VectorIterator operator-(const size_t value) {
    VectorIterator tmp(this->ptr_ - value);
    return tmp;
  }
  bool operator==(const VectorIterator& other) const {
    return ptr_ == other.ptr_;
  }
  bool operator!=(const VectorIterator& other) const {
    return ptr_ != other.ptr_;
  }
  reference_type operator*() const { return (*ptr_); }
  pointer_type operator->() { return ptr_; }

  operator VectorConstIterator<T>() const {
    return VectorConstIterator<T>(ptr_);
  }

 private:
  pointer_type ptr_;
};

template <typename T>
class VectorConstIterator {
  friend class Vector<T>;
  friend class VectorIterator<T>;

 public:
  using value_type = T;
  using pointer_type = T*;
  using reference_type = T&;

  VectorConstIterator() : ptr_(){};
  VectorConstIterator(pointer_type ptr) : ptr_(ptr) {}

  VectorConstIterator& operator++() {
    ptr_++;
    return *this;
  }
  VectorConstIterator operator++(int) {
    VectorConstIterator tmp = *this;
    ++(*this);
    return tmp;
  }
  VectorConstIterator& operator--() {
    ptr_--;
    return *this;
  }
  VectorConstIterator operator--(int) {
    VectorConstIterator tmp = *this;
    --(*this);
    return tmp;
  }
  bool operator==(const VectorConstIterator& other) {
    return ptr_ == other.ptr_;
  }
  bool operator!=(const VectorConstIterator& other) {
    return ptr_ != other.ptr_;
  }
  reference_type operator*() const { return (*ptr_); }
  pointer_type operator->() { return ptr_; }

  operator VectorIterator<T>() const { return VectorIterator<T>(ptr_); }

 private:
  pointer_type ptr_;
};
}  // namespace s21

#endif  // SRC_S21_CONTAINERS_VECTOR_S21_VECTOR_H_