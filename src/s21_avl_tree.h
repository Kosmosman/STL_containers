#ifndef CPP_CONTAINERS_S21_AVL_TREE_H_
#define CPP_CONTAINERS_S21_AVL_TREE_H_

#include <algorithm>
#include <initializer_list>
namespace s21 {

template <typename K, typename V>
struct Node {
  Node();
  Node(K o_value, int o_height);

  Node* NextNode();
  Node* PreviousNode();

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

  node_type* Insert(const K& key);
  void Merge(AvlTree& other);
  void Erase(node_type*);
  node_type* Find(const K& key);
  node_type* LowerBound(const K& key);
  void Clear();

  bool Empty() const;
  size_t GetSize() const;
  size_t MaxSize() const;

  AvlTree& operator=(const AvlTree& other);
  AvlTree& operator=(AvlTree&& other);

  node_type* Begin();
  node_type* End();

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
    const K& operator*();
  };

 private:
  size_t size_;
  node_type* head_;

  void DeleteNodes(node_type* node);
  void SwapNode(node_type* one, node_type* two);

  AvlTree& CopyTree(node_type* node, const node_type* other_node);
  AvlTree& SwapTree(AvlTree<K, V>&& other_tree);

  node_type* InnerInsert(node_type* node, const K& key);

  void Balance(node_type* node, int diff);
  int GetBalance(const node_type* node) const;
  void BalanceAfterErace(node_type* node);

  int GetHeight(const node_type* node) const;
  void UpdateHeight(node_type* node);

  void LeftRotate(node_type* node);
  void RightRotate(node_type* node);

  node_type* FindExtremum(node_type* node, int balance);

  void CreateEnd();
};
};  // namespace s21

#include "s21_avl_tree.tpp"

#endif  // CPP_CONTAINERS_S21_AVL_TREE_H_