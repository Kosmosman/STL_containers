#ifndef CPP_CONTAINERS_S21_AVL_TREE_H_
#define CPP_CONTAINERS_S21_AVL_TREE_H_

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <list>
#include <queue>
namespace s21 {

template <typename K, typename V>
struct Node {
  Node();
  Node(K o_value, int o_height);

  Node<K, V>* NextNode();
  Node<K, V>* PreviousNode();

  K value;
  int height;
  Node *parent = nullptr, *left = nullptr, *right = nullptr;
};

template <typename K, typename V>
class AvlTree {
 public:
  class Iterator;
  class ConstIterator;

  using node_type = Node<K, V>;
  using reference = V&;
  using const_reference = const V&;
  using iterator = Iterator;
  using const_iterator = ConstIterator;

  AvlTree() noexcept;
  explicit AvlTree(std::initializer_list<K> const& init);
  explicit AvlTree(const AvlTree& other);
  AvlTree(AvlTree&& other) noexcept;
  ~AvlTree();

  Node<K, V>* Insert(const K& key);
  void Merge(AvlTree& other);
  void Erase(Node<K, V>*);
  Node<K, V>* Find(const K& key);
  void Clear();

  bool Empty() const;
  size_t GetSize() const;
  size_t MaxSize() const;

  AvlTree& operator=(const AvlTree& other);
  AvlTree& operator=(AvlTree&& other);

  Node<K, V>* Begin();
  Node<K, V>* End();

  void PrintTree();

  class Iterator {
   public:
    Iterator();
    explicit Iterator(node_type* node);
    Iterator(const iterator& other);
    Iterator(iterator&& other);

    iterator& operator++();
    iterator operator++(int);
    iterator& operator--();
    iterator operator--(int);
    iterator& operator=(const iterator& s);
    iterator& operator=(iterator&& s);
    bool operator!=(const iterator& it);
    bool operator==(const iterator& it);
    K& operator*();

   protected:
    node_type* iterator_node_;
  };

  class ConstIterator : public Iterator {
   public:
    ConstIterator() : Iterator{} {};
    explicit ConstIterator(node_type* node) : Iterator{node} {};
    ConstIterator(const const_iterator& other) : Iterator{other} {};
    ConstIterator(const iterator& other) : Iterator{other} {};
    ConstIterator(const_iterator&& other) : Iterator{std::move(other)} {};
  };

 private:
  size_t size_;
  Node<K, V>* head_;

  void DeleteNodes(Node<K, V>* node);
  Node<K, V>* InnerInsert(Node<K, V>* node, const K& key);
  void Balance(Node<K, V>* node, int diff);
  void SwapNode(Node<K, V>* one, Node<K, V>* two);
  AvlTree& SwapTree(AvlTree<K, V>&& other_tree);
  void LeftRotate(Node<K, V>* node);
  void RightRotate(Node<K, V>* node);
  void UpdateHeight(Node<K, V>* node);
  Node<K, V>* FindExtremum(Node<K, V>* node, int balance);
  int GetHeight(const Node<K, V>* node) const;
  int GetBalance(const Node<K, V>* node) const;
  void CopyNode(Node<K, V>* node, const Node<K, V>* other_node);
  AvlTree& CopyTree(Node<K, V>* node, const Node<K, V>* other_node);
  void BalanceAfterErace(Node<K, V>* node);
  void CreateEnd();
};
};  // namespace s21

#include "s21_avl_tree.tpp"

#endif  // CPP_CONTAINERS_S21_AVL_TREE_H_