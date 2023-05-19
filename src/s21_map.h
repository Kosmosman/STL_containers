#ifndef CPP_CONTAINERS_S21_MAP_H_
#define CPP_CONTAINERS_S21_MAP_H_

#include <utility>

#include "s21_avl_tree.h"

namespace s21 {

template <typename K, typename V>
class Map {
 public:
  class MapIterator;
  class MapConstIterator;

  using key_type = K;
  using mapped_type = V;
  using value_type = std::pair<const key_type, mapped_type>;
  using referensce = value_type &;
  using const_reference = const value_type &;
  using iterator = MapIterator<K, V>;
  using const_iterator = MapConstIterator<K, V>;
  using size_type = size_t;

  Map();
  Map(std::initializer_list<value_type> const &items);
  Map(const Map &m);
  Map(Map &&m);
  ~Map(){};

 private:
  AvlTree<key_type, mapped_type> tree;
};
};  // namespace s21

#endif  // CPP_CONTAINERS_S21_MAP_H_