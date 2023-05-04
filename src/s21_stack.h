#ifndef SRC_S21_STACK_H_
#define SRC_S21_STACK_H_

namespace s21 {
template <typename T>
class Stack {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

  Stack();
  Stack(std::initializer_list<value_type> const& items);
  Stack(const Stack& s);
  Stack(Stack&& s) noexcept;
  Stack<T>& operator=(Stack&& s) noexcept;
  ~Stack();

  const_reference top() const;
  reference top();
  bool empty();
  size_type size();
  void push(const_reference value);
  void pop();
  void swap(Stack& other);
  // void emplace_front(Args&&... args);

 private:
  struct Node {
    value_type value;
    Node* next;
  };

  Node* head_;
  size_type size_;
};
};  // namespace s21
#include "s21_stack.tpp"
#endif  // SRC_S21_STACK_H_