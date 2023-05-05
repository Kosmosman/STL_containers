// это можно убрать
#include "s21_queue.h"

namespace s21 {

/*
 * @brief Default constructor, default constructor, creates an empty queue
 */
template <typename T>
Queue<T>::Queue() : first_(nullptr), last_(nullptr), size_(0) {}

/*
 * @brief Initializer list constructor, creates queue initizialized using
 * std::initializer_list
 */
template <typename T>
Queue<T>::Queue(std::initializer_list<value_type> const &items)
    : first_(nullptr), last_(nullptr), size_(0) {
  for (auto it = items.begin(); it < items.end(); it++) {
    push(*it);
  }
  //   for (const auto & item : items) {
  //     push(item);
  //   }
}

/*
 * @brief Copy constructor
 */
template <typename T>
Queue<T>::Queue(const Queue &q) : first_(nullptr), last_(nullptr), size_(0) {
  Node *tmp = q.first_;
  while (tmp) {
    push(tmp->value);
    tmp = tmp->next;
  }
}

/*
 * @brief Move constructor
 */
template <typename T>
Queue<T>::Queue(Queue &&q) noexcept
    : first_(q.first_), last_(q.last_), size_(q.size_) {
  q.first_ = nullptr;
  q.last_ = nullptr;
  q.size_ = 0;
}

/*
 * @brief Assignment operator overload for moving an object
 */
template <typename T>
Queue<T> &Queue<T>::operator=(Queue &&q) noexcept {
  if (*this == q) return *this;

  ~Queue();
  first_ = q.first_;
  last_ = q.last_;
  size_ = q.size;
}

/*
 * @brief Destructor
 */
template <typename T>
Queue<T>::~Queue() {
  Node *tmp = nullptr;
  while (first_ != nullptr) {
    tmp = first_;
    first_ = first_->next;
    delete tmp;
    tmp = nullptr;
  }
}

/*
 * @brief Get value of the fist element
 */
template <typename T>
typename Queue<T>::const_reference Queue<T>::front() const {
  return first_->value;
}

/*
 * @brief Get access to the frist element
 */
template <typename T>
typename Queue<T>::reference Queue<T>::front() {
  return first_->value;
}

/*
 * @brief Get value of the last element
 */
template <typename T>
typename Queue<T>::const_reference Queue<T>::back() const {
  return last_->value;
}

/*
 * @brief Get access to the last element
 */
template <typename T>
typename Queue<T>::reference Queue<T>::back() {
  return last_->value;
}

/*
 * @brief Checks whether the container is empty
 */
template <typename T>
bool Queue<T>::empty() {
  return size_ == 0;
}

/*
 * @brief Returns the number of elements
 */
template <typename T>
typename Queue<T>::size_type Queue<T>::size() {
  return size_;
}

/*
 * @brief Inserts an element at the end
 */
template <typename T>
void Queue<T>::push(const_reference value) {
  Node *tmp = new Node();
  tmp->value = value;
  tmp->next = nullptr;
  if (first_ == nullptr) {
    first_ = tmp;
    last_ = tmp;
  } else {
    last_->next = tmp;
    last_ = last_->next;
  }

  size_ += 1;
}

/*
 * @brief Removes the first element
 */
template <typename T>
void Queue<T>::pop() {
  if (first_) {
    Node *tmp = first_;
    first_ = first_->next;
    delete tmp;
    tmp = nullptr;
    size_ -= 1;
  }
}

/*
 * @brief Swaps the contents
 */
template <typename T>
void Queue<T>::swap(Queue &other) {
  std::swap(first_, other.first_);
  std::swap(last_, other.last_);
  std::swap(size_, other.size_);
}

/* 
* @brief Appends new elements to the end of the queue
* @tparam T 
* @param ...args 
*/
template <typename T>
template <typename... Args>
void Queue<T>::emplace_back(Args &&...args) {
  value_type temp(std::forward<Args>(args)...);
  push(temp);
};

};  // namespace s21