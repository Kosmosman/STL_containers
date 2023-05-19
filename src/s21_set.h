#ifndef CPP_CONTAINERS_S21_SET_H_
#define CPP_CONTAINERS_S21_SET_H_

#include <memory>

#include "s21_avl_tree.h"

namespace s21 {
template <typename Key>
class Set {
 public:
  class SetIterator;
  class SetConstIterator;

  using key_type = Key;
  using value_type = Key;
  using node_type = Node<key_type, value_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = SetIterator;
  using const_iterator = SetConstIterator;
  using size_type = size_t;

  Set();
  Set(std::initializer_list<value_type> const &items);
  Set(const Set &s);
  Set(Set &&s);
  ~Set(){};

  Set &operator=(const Set &s);
  Set &operator=(Set &&s);

  iterator begin();
  iterator end();

  bool Empty();
  size_type Size();
  size_type Max_size();

  void Clear();
  std::pair<iterator, bool> Insert(const value_type &value);
  void Erase(iterator pos);
  void Swap(Set &other);
  void Merge(Set &other);

  iterator Find(const key_type &key);
  bool Contains(const key_type &key);

  class SetIterator {
   public:
    SetIterator();
    explicit SetIterator(node_type *node);
    SetIterator(const iterator &other);
    SetIterator(iterator &&other);

    iterator &operator++();
    iterator operator++(int);
    iterator &operator--();
    iterator operator--(int);
    iterator &operator=(const iterator &s);
    iterator &operator=(iterator &&s);
    bool operator!=(const iterator &it);
    bool operator==(const iterator &it);
    reference operator*();

   protected:
    node_type *iterator_node_;
  };

  class SetConstIterator : public SetIterator {
   public:
    SetConstIterator() : SetIterator{} {};
    explicit SetConstIterator(node_type *node) : SetIterator{node} {};
    SetConstIterator(const const_iterator &other) : SetIterator{other} {};
    SetConstIterator(const iterator &other) : SetIterator{other} {};
    SetConstIterator(const_iterator &&other) : SetIterator{std::move(other)} {};

    const_reference operator*();
  };

 private:
  AvlTree<key_type, value_type> tree;
};
};  // namespace s21

#include "s21_set.tpp"

#endif  // CPP_CONTAINERS_S21_SET_H_
