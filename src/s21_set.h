#ifndef CPP_CONTAINERS_S21_SET_H_
#define CPP_CONTAINERS_S21_SET_H_

#include "s21_avl_tree.h"

namespace s21 {
template <typename K>
class Set {
 public:
  class SetIterator;
  class SetConstIterator;

  using key_type = K;
  using value_type = K;
  using referensce = value_type &;
  using const_reference = const value_type &;
  using iterator = SetIterator<K>;
  using const_iterator = SetConstIterator<K>;
  using size_type = size_t;

  class SetIterator {
   public:
    SetIterator() : iterator_node_{nullptr} {};
    explicit SetIterator(Node<key_type, value_type> *node)
        : iterator_node_(node){};
    SetIterator &operator++(){};
    referensce operator->(){};
    value_type operator*() { return iterator_node_->key; }

   private:
    Node<key_type, value_type> *iterator_node_;
  };
  class SetConstIterator {};

  Set() : tree{} {};
  Set(std::initializer_list<value_type> const &items) : tree{items} {};
  Set(const Set &s) : tree{s.tree} {};
  Set(Set &&s) : tree{std::move(s.tree)} {};
  Set &operator=(const Set &s);
  Set &operator=(Set &&s);
  ~Set() { tree.Clear(); };

  iterator Begin() { return iterator(tree.Begin()); };
  iterator End() { return iterator(tree.End()); };

  bool Empty() { return tree.Empty(); };
  size_type Size() { return tree.GetSize(); };
  size_type Max_size(){return std::numeric_limits<size_type>::max() /
                              sizeof(value_type)};

  void Clear() { tree.Clear(); };
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

#include "s21_set.tpp"

#endif  // CPP_CONTAINERS_S21_SET_H_