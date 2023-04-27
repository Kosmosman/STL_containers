#ifndef CPP_CONTAINERS_S21_SET_H_
#define CPP_CONTAINERS_S21_SET_H_

#include "s21_avl_tree.h"

namespace s21 {
template <typename K>
class Set {
 public:
  using key_type = K;
  using value_type = K;
  using referensce = value_type &;
  using const_reference = const value_type &;
  using iterator = SetIterator<K>;
  using const_iterator = SetConstIterator<K>;
  using size_type = size_t;

  Set() : tree(){};
  Set(std::initializer_list<value_type> const &items) : tree{items} {};
  Set(const Set &s);
  Set(Set &&s);
  ~Set();

  operator=(Set &&s);

  bool Empty();
  size_type Size();
  size_type Max_size();

  void Clear();
  std::pair<iterator, bool> Insert(const value_type &value);
  void Erase(iterator pos);
  void Swap(Set &other);
  void Merge(Set &other);

  iterator Find(const Key &key);
  bool Contains(const Key &key);

 private:
  AvlTree<key_type, value_type> tree;
};

};  // namespace s21

#endif  // CPP_CONTAINERS_S21_SET_H_