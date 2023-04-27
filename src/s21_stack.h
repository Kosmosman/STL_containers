#ifndef SRC_S21_STACK_H_
#define SRC_S21_STACK_H_
// #include <iostream>
#include <iostream>

namespace s21 {
template <typename T>
class Stack {  // Почему нужно с маленькой?
 public:
  Stack();
  Stack(const Stack& s);

  Stack(Stack&& s) noexcept;
  ~Stack();

  using value_type = T;
  using reference = T&; // зачем это, если я его нигде не использовал?
  using const_reference = const T&;
  using size_type = size_t;

  Stack(std::initializer_list<value_type> const& items);

  void push(const_reference node);
  void pop();
  bool empty();
  size_type size();
  const_reference top();

  void swap(Stack& other);
  // почему по заданию без Stack<T>& ?
  Stack<T>& operator=(Stack&& s);

 private:
  struct Node {
    T value;
    Node* next;
  };

  Node* head_;
  size_type size_;
};
};  // namespace s21
#include "s21_Stack.tpp"
#endif  // SRC_S21_STACK_H_