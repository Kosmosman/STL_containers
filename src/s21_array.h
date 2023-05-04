#ifndef SRC_S21_ARRAY_H_
#define SRC_S21_ARRAY_H_
namespace s21 {
template <typename T, size_t N>
class Array {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = size_t;

  Array();
  Array(std::initializer_list<value_type> const &items);
  Array(const Array &a);
  // Array(const Array<T, N> &a);
  Array(Array &&a);
  Array<T, N>& operator=(Array &&a);
  ~Array();

  reference at(size_type pos); // может нужна перегрузка constexpr
  reference operator[](size_type pos);
  const_reference front() const;
  reference front();
  const_reference back() const;
  reference back();
  iterator data(); // или написать свой итератор?  
  iterator begin();
  iterator end();
  bool empty();
  size_type size();
  size_type max_size();
  void swap(Array& other);
  void fill(const_reference value);
 private:
  value_type arr_[N];
  iterator begin_;
  iterator end_;
  size_type size_;
};
};  // namespace s21

#include "s21_array.tpp"
#endif  // SRC_S21_QUEUE_H_