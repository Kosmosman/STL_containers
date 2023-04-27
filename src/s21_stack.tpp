
// это можно убрать
#include "s21_Stack.h"

namespace s21 {
template <typename T>
Stack<T>::Stack() : head_(nullptr), size_(0) {}

template <typename T>
Stack<T>::Stack(const Stack &s) : head_(nullptr), size_(0) {
  Node **this_p = &head_;
  Node *other_p = s.head_;

  while (other_p) {
    *this_p = new Node();
    (*this_p)->value = other_p->value;
    this_p = &((*this_p)->next);
    other_p = other_p->next;
    size_ += 1;
  }
}

template <typename T>
Stack<T>::Stack(std::initializer_list<value_type> const &items)
    : head_(nullptr), size_(0) {
  for (auto it = items.begin(); it < items.end(); it++) {
    push(*it);
  }
}

// или лучше swap?
template <typename T>
// почему тут точки, а не стрелочки. Это разве нее ссылки?
Stack<T>::Stack(Stack &&s) noexcept : head_(s.head_), size_(s.size_) {
  s.head_ = nullptr;
  s.size_ = 0;
}

template <typename T>
Stack<T>::~Stack() {
  Node *tmp = nullptr;
  while (head_ != nullptr) {
    tmp = head_;
    head_ = head_->next;
    delete tmp;
    tmp = nullptr;
  }
}

template <typename T>
void Stack<T>::push(const_reference value) {
  Node *node = new Node();
  node->value = value;
  node->next = head_;
  head_ = node;
  size_ += 1;
}

template <typename T>
typename Stack<T>::size_type Stack<T>::size() {
  return size_;
}

template <typename T>
bool Stack<T>::empty() {
  return size_ == 0;
}

template <typename T>
void Stack<T>::pop() {
  if (head_) {
    Node *temp_node = head_;
    head_ = head_->next;
    delete temp_node;
    temp_node = nullptr;
    size_ -= 1;
  }
}

template <typename T>
// нужен тест на top() = 5; В оригинале она заменяет
typename Stack<T>::const_reference Stack<T>::top() {
  return head_->value;
}

template <typename T>
void Stack<T>::swap(Stack &other) {
  std::swap(head_, other.head_);
  std::swap(size_, other.size_);
}

template <typename T>
// как перезаписать?
Stack<T> &Stack<T>::operator=(Stack &&s) {
  if (*this == s) return *this;

  // почему деструктро только через this?
  *this->~Stack();
  // или swap?
  // std::swap(head_, s.head_);
  // std::swap(size_, s.size_);
  head_ = s.head_;
  size_ = s.size_;

  s.head_ = nullptr;
  s.size_ = 0;

  return *this;
}
};  // namespace s21
