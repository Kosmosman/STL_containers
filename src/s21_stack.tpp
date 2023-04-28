
// это можно убрать
#include "s21_Stack.h"

namespace s21 {
/*
 * @brief Default constructor, creates empty stack
 */
template <typename T>
Stack<T>::Stack() : head_(nullptr), size_(0) {}

/*
 * @brief Initializer list constructor, creates stack initizialized using
 * std::initializer_list
 */
template <typename T>
Stack<T>::Stack(std::initializer_list<value_type> const &items)
    : head_(nullptr), size_(0) {
  for (auto it = items.begin(); it < items.end(); it++) {
    push(*it);
  }
}

/*
 * @brief Copy constructor
 */
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

/*
 * @brief Move constructor
 */
template <typename T>
Stack<T>::Stack(Stack &&s) noexcept : head_(s.head_), size_(s.size_) {
  s.head_ = nullptr;
  s.size_ = 0;
}

/*
 * @brief Assignment operator overload for moving object
 */
template <typename T>
Stack<T> &Stack<T>::operator=(Stack &&s) noexcept {
  if (*this == s) return *this;

  ~Stack();
  head_ = s.head_;
  size_ = s.size_;

  s.head_ = nullptr;
  s.size_ = 0;

  return *this;
}

/*
 * @brief Destructor
 */
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

/*
 * @brief Get value of the top value
 */
template <typename T>
typename Stack<T>::const_reference Stack<T>::top() const {
  return head_->value;
}

/*
 * @brief Get access to the top value
 */
template <typename T>
typename Stack<T>::reference Stack<T>::top() {
  return head_->value;
}

/*
 * @brief Checks whether the container is empty
 */
template <typename T>
bool Stack<T>::empty() {
  return size_ == 0;
}

/*
 * @brief Returns the number of elements
 */
template <typename T>
typename Stack<T>::size_type Stack<T>::size() {
  return size_;
}

/*
 * @brief Inserts value at the top
 */
template <typename T>
void Stack<T>::push(const_reference value) {
  Node *node = new Node();
  node->value = value;
  node->next = head_;
  head_ = node;
  size_ += 1;
}

/*
 * @brief Removes the top element
 */
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

/*
 * @brief Swaps the contents
 */
template <typename T>
void Stack<T>::swap(Stack &other) {
  std::swap(head_, other.head_);
  std::swap(size_, other.size_);
}

};  // namespace s21
