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
};
};  // namespace s21

#include "s21_array.tpp"
#endif  // SRC_S21_QUEUE_H_