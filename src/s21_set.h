#ifndef SRC_S21_SET_H_
#define SRC_S21_SET_H_
namespace s21 {
template <typenmae Key>
class Set {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using const_reference = const value_type&;
  //   using iterator =
  //   using const_iterator =
  using size_type = size_t;

  Set();
};
};  // namespace s21

#include "s21_set.tpp"
#endif  // SRC_S21_SET_H_