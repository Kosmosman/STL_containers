#ifndef CPP_CONTAINERS_S21_SET_H_
#define CPP_CONTAINERS_S21_SET_H_

#include "s21_avl_tree.h"

namespace s21 {
template <typename Key>
class Set {
 public:
  class SetIterator;
  class SetConstIterator;

  using key_type = Key;
  using value_type = Key;
  using referensce = value_type &;
  using const_reference = const value_type &;
  using iterator = SetIterator;
  using const_iterator = SetConstIterator;
  using size_type = size_t;

  class SetIterator {
   public:
    SetIterator() : iterator_node_{nullptr} {};
    explicit SetIterator(Node<key_type, value_type> *node)
        : iterator_node_{node} {};
    iterator &operator++();
    iterator &operator++(int);
    iterator &operator--();
    iterator &operator--(int);
    iterator &operator=(const iterator &s);
    iterator &operator=(iterator &&s);
    bool operator!=(const iterator &it) {
      return iterator_node_ != it.iterator_node_;
    };
    value_type operator*() { return iterator_node_ ? iterator_node_->key : 0; };

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
  ~Set(){};

  iterator begin() { return iterator(tree.Begin()); };
  iterator end() { return iterator(tree.End()); };

  bool Empty() { return tree.Empty(); };
  size_type Size() { return tree.GetSize(); };
  size_type Max_size() {
    return std::numeric_limits<size_type>::max() / sizeof(value_type);
  };

  void Clear() { tree.Clear(); };
  std::pair<iterator, bool> Insert(const value_type &value);
  void Erase(iterator pos);
  void Swap(Set &other);
  void Merge(Set &other);

  iterator Find(const key_type &key) { return iterator(tree.Find(key)); };
  bool Contains(const key_type &key) { return tree.Find(key); };

 private:
  AvlTree<key_type, value_type> tree;
};

};  // namespace s21

#include "s21_set.tpp"

#endif  // CPP_CONTAINERS_S21_SET_H_