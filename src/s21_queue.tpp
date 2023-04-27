#include "s21_queue.h"

namespace s21 {
  
  template <typename T>
  Queue<T>::Queue() : first_(nullptr), last_(nullptr) {}

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

  template <typename T>
  typename Queue<T>::const_reference Queue<T>::front() const {
       return first_->value;
  }

  template <typename T>
  typename Queue<T>::const_reference Queue<T>::back() const {
       return last_->value;
  }

};  // namespace s21