#ifndef S21_LIST_H
#define S21_LIST_H

#include "s21_list.h"


reference operator*() {
    if (!this->ptr_) {
        throw std::invalid_argument("Value is nullptr");
    }
    return this->ptr_->value_;
}
ListIterator operator++(int) {
    ptr_ = ptr_->next_;
    return *this;
}
ListIterator operator--(int) {
    ptr_ = ptr_->prev_;
    return *this;
}
ListIterator& operator++() {
    ptr_ = ptr_->next_;
    return *this;
}
ListIterator& operator--() {
    ptr_ = ptr_->prev_;
    return *this;
}
bool operator==(ListIterator other) { return this->ptr_ == other.ptr_; }

bool operator!=(ListIterator other) { return this->ptr_ != other.ptr_; }

const T& operator*() { return ListIterator::operator*(); }


























#endif  // S21_LIST_H