namespace s21 {


    template <typename value_type>
    list<value_type>::list() {}

    template <typename value_type>
    list<value_type>::list(size_type n) {}
//// empty size max_size
    template <typename value_type>
    bool list<value_type>::empty() {
        return size_ == 0;
    }
    template <typename value_type>
    typename list<value_type>::size_type list<value_type>::size() {
        return size_;
    }

    //// iterator /////////////////////////////////////////////////////
template <typename value_type>
typename list<value_type>::reference list<value_type>::iterator::operator*() {
    if (!this->ptr_) {
        throw std::invalid_argument("Value is nullptr");
    }
    return this->ptr_->value_;
}
template <typename value_type>
typename list<value_type>::iterator list<value_type>::iterator::operator++(int) {
    ptr_ = ptr_->next_;
    return *this;
}
template <typename value_type>
typename list<value_type>::iterator list<value_type>::iterator::operator--(int) {
    ptr_ = ptr_->prev_;
    return *this;
}
template <typename value_type>
typename list<value_type>::iterator& list<value_type>::iterator::operator++() {
    ptr_ = ptr_->next_;
    return *this;
}
template <typename value_type>
typename list<value_type>::iterator& list<value_type>::iterator::operator--() {
    ptr_ = ptr_->prev_;
    return *this;
}

template <typename value_type>
bool list<value_type>::iterator::operator==(ListIterator other) {
    return this->ptr_ == other.ptr_;
}

template <typename value_type>
bool list<value_type>::iterator::operator!=(ListIterator other) {
    return this->ptr_ != other.ptr_;
}

template <typename value_type>
typename list<value_type>::const_reference list<value_type>::const_iterator::operator*() const {
    return ListIterator::operator*();
}

//    list<value_type>::reference list<value_type>::iterator::

template <typename value_type>
typename list<value_type>::iterator list<value_type>::begin() {
    if (head_) {
        return iterator(head_);
    } else {
        return iterator(end_);
    }
//     return iterator(end_->next_);
//    return !head_ ? iterator(end_) : iterator(head_);
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::end() {
    return iterator(end_);
}
};