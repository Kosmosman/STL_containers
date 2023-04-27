#ifndef SRC_S21_QUEUE_H_
#define SRC_S21_QUEUE_H_

namespace s21 {
template <typename T>
class Queue {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

  Queue();
  
 private:
  struct Node {
    value_type value;
    Node* next;
  };

  Node* first_;
  Node* last_;
  size_type size_;
};
};  // namespace s21
#include "s21_queue.tpp"
#endif  // SRC_S21_QUEUE_H_