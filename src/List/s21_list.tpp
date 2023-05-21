#ifndef S21_LIST_H
#define S21_LIST_H

template <typename value_type>
reference operator*() {
    if (!this->ptr_) {
        throw std::invalid_argument("Value is nullptr");
    }
    return this->ptr_->value_;
}
template <typename value_type>
ListIterator list<value_type>::iterator list<value_type>::iterator::operator++(int) {
    ptr_ = ptr_->next_;
    return *this;
}
template <typename value_type>
ListIterator list<value_type>::iterator list<value_type>::iterator::operator--(int) {
    ptr_ = ptr_->prev_;
    return *this;
}
//template <typename value_type>
//ListIterator& operator++() {
//    ptr_ = ptr_->next_;
//    return *this;
//}
//template <typename value_type>
//ListIterator&   operator--() {
//    ptr_ = ptr_->prev_;
//    return *this;
}
template <typename value_type>
bool list<value_type>::iterator::operator==(ListIterator other) { return this->ptr_ == other.ptr_; }

template <typename value_type>
bool list<value_type>::iterator::operator!=(ListIterator other) { return this->ptr_ != other.ptr_; }

template <typename value_type>
const T& operator*() { return ListIterator::operator*(); }

template <typename value_type>
typename list<value_type>::iterator list<value_type>::begin() {
//    if (head_) {
//        return iterator(head_);
//    } else {
//        return iterator(end_);
//    }
     return iterator(end_node->next)
//    return !head_ ? iterator(end_) : iterator(head_);
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::end() {
    return iterator(end_);
}


















#endif  // S21_LIST_H