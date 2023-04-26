#ifndef CPP_CONTAINERS_S21_AVL_TREE_H_
#define CPP_CONTAINERS_S21_AVL_TREE_H_

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <queue>

namespace s21 {

template <typename K, typename V>
struct Node {
  Node() : key(0), value(0), height(0){};
  Node(K o_key, V o_value, int o_height)
      : key(o_key), value(o_value), height(o_height){};
  K key;
  V value;
  int height;
  Node *parent = nullptr, *left = nullptr, *right = nullptr;
};

template <typename K, typename V>
class AvlTree {
 public:
  class TreeIterator {
   public:
    using iterator = AvlTree<K, V>::TreeIterator;
    TreeIterator() : iterator_node_(nullptr){};
    operator++(){};
    operator->(){};
    iterator& Begin();
    iterator& End();

   private:
    Node<K, V>* iterator_node_;
  };

  class ConstTreeIterator {
    using const_iterator = AvlTree<K, V>::ConstTreeIterator;
  };

  AvlTree() noexcept;
  explicit AvlTree(std::initializer_list<K> init);
  explicit AvlTree(const AvlTree& other);
  AvlTree(AvlTree&& other) noexcept;
  ~AvlTree();

  void Insert(const K& key, const V& value);
  void Erase(const K& key);
  Node<K, V>* Find(const K& key);
  size_t GetSize() const { return size_; };

  void PrintTree();

 private:
  size_t size_;
  Node<K, V>* head_;

  void Clear(Node<K, V>* node);
  void InnerInsert(Node<K, V>* node, const K& key, const V& value);
  bool InnerErase(Node<K, V>* node, const K& key);
  Node<K, V>* InnerFind(Node<K, V>* node, const K& key, bool& res);
  void Balance(Node<K, V>* node, int diff);
  void SwapNode(Node<K, V>* one, Node<K, V>* two);
  void LeftRotate(Node<K, V>* node);
  void RightRotate(Node<K, V>* node);
  void UpdateHeight(Node<K, V>* node);
  Node<K, V>* FindExtremum(Node<K, V>* node, int balance);
  int GetHeight(const Node<K, V>* node) const;
  int GetBalance(const Node<K, V>* node) const;
  void CopyTree(Node<K, V>* node, const Node<K, V>* other_node);
  void CopyNode(Node<K, V>* node, const Node<K, V>* other_node);
};
};  // namespace s21

#include "s21_avl_tree.tpp"

#endif  // CPP_CONTAINERS_S21_AVL_TREE_H_