namespace s21 {

//// Constructs
    template <typename value_type>
    list<value_type>::list() : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
        end_ = new Node(size_);
        change_end();
    }

    template <typename value_type>
    list<value_type>::list(size_type n)
            : list() {
        const_reference val = value_type();
        for (size_type i = 0; i < n; ++i) {
            insert(end(), val);
        }
        change_end();
    }
    template <typename value_type>
    list<value_type>::list(std::initializer_list<value_type> const& items)
            : list() {
        for (const auto& item : items) {
            push_back(item);
            change_end();
        }
    }

        template <typename value_type>
        list<value_type>::list(const list& l)
                : list() {
            *this = l;
    }

    template <typename value_type>
    list<value_type>& list<value_type>::operator=(const list& l) {
        if (this == &l) {
            throw std::out_of_range("Coping the same list is forbidden!");
        }
        clear();
        Node* current = l.head_;
        for (size_type i = 0; i < l.size_; i++) {
            push_back(current->value_);
            current = current->next_;
        }
        return *this;
    }

    template <typename value_type>
    list<value_type>::list(list&& l) {
        swap(l);
    }

    template <typename value_type>
    void list<value_type>::swap(list& other) {
        std::swap(this->head_, other.head_);
        std::swap(this->tail_, other.tail_);
        std::swap(this->end_, other.end_);
        std::swap(this->size_, other.size_);
    }

    template <typename value_type>
    void list<value_type>::splice(ListConstIterator pos, list& other) {
                auto end = other.end();
                auto iter = other.begin();
                while(iter != end) {
                    insert(pos, *iter);
                    ++iter;
                }
    }

    template <typename value_type>
    list<value_type>& list<value_type>::operator=(list&& l) {
        this->swap(l);
        l.clear();
        return *this;
    }
    template <typename value_type>
    void list<value_type>::clear() {
        while (empty() == false) pop_front();
    }
    template <typename value_type>
    void list<value_type>::erase(ListIterator pos) {
        Node* node = pos.ptr_;

        if (node == nullptr || node == end_) {
            throw std::invalid_argument("Invalid argument");
        }
        if (node == head_) {
            head_ = node->next_;
        } else {
            node->prev_->next_ = node->next_;
        }
        if (node == tail_) {
            tail_ = node->prev_;
        } else {
            node->next_->prev_ = node->prev_;
        }
        delete node;
        --size_;
    }

    template <typename value_type>
    void list<value_type>::pop_front(){erase(begin());
    }
    template <typename value_type>
    void list<value_type>::pop_back() { erase(--end()); }



    template <typename value_type>
    typename list<value_type>::const_reference	list<value_type>::front() { return *begin(); }

    template <typename value_type>
    typename list<value_type>::const_reference	list<value_type>::back()  { return *(--end()); }


    template <typename value_type>
    void list<value_type>::change_end() {
        if (end_) {
            end_->next_ = head_;
            end_->prev_ = tail_;
            end_->value_ = size();
            if (head_) {
                head_->prev_ = end_;
            }
                        if (tail_) {
                tail_->next_ = end_;
            }
        }
    }
//// push`s
    template <typename value_type>
    void list<value_type>::push_back(const_reference value) {
        insert(end(), value);
    }

    //// insert & erase

    template <typename value_type>
    typename list<value_type>::iterator list<value_type>::insert(iterator pos,
                                                                 const_reference value) {
        Node* active = pos.ptr_;
        Node* add = new Node(value);
        setNewValueForList(active, add);
        size_++;
        //// method in zero pool node
        change_end();
        return iterator(add);

    }
    //// доп func
    template <typename value_type>
   void list<value_type>::setNewValueForList(Node* active, Node* add) {
       empty() ? installationInBlankList(add) : installationNotInBlankList(active,add);
    }

    template <typename value_type>
    void list<value_type>::installationInBlankList(Node* add) {
        add->next_ = end_;
        add->prev_ = end_;
        head_ = add;
        tail_ = add;
    }
    template <typename value_type>
    void list<value_type>::installationNotInBlankList(Node* active, Node* add) {
        if (active == head_) {
            head_ = add;
        } else if (active == end_) {
            tail_ = add;
        }
        add->next_ = active;
        add->prev_ = active->prev_;
        active->prev_->next_ = add;
        active->prev_ = add;
    }

    //TODO merge
    template<typename value_type>
    void list<value_type>::merge(list& other) {
        if (this != &other && !other.empty()) {
        auto mergedList = list<value_type>();
        iterator it1 = begin();
        iterator it2 = other.begin();

        while (it1 != end() && it2 != other.end()) {
            if (*it1 <= *it2) {
                mergedList.push_back(*it1);
                ++it1;
            } else {
                mergedList.push_back(*it2);
                ++it2;
            }
        }
        while (it1 != end()) {
            mergedList.push_back(*it1);
            ++it1;
        }
        while (it2 != other.end()) {
            mergedList.push_back(*it2);
            ++it2;
        }
        *this = std::move(mergedList);

        other.clear();
    }
    }







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

//    void		push_front(const_refe &val) { insert(begin(), val); }
template <typename value_type>
void  list<value_type>::push_front(const_reference value) {
    insert(begin(), value);
    }

template <typename value_type>
typename list<value_type>::iterator list<value_type>::begin() {
//    if (head_) {
//        return iterator(head_);
//    } else {
//        return iterator(end_);
//    }
//     return iterator(end_->next_);
    return !head_ ? iterator(end_) : iterator(head_);
//    return iterator(head_);
}
    template <typename value_type>
    typename list<value_type>::iterator list<value_type>::end() {
        return iterator(end_);
    }

    template <typename value_type>
    typename list<value_type>::const_iterator list<value_type>::begin() const {
        return !head_ ? const_iterator(end_) : const_iterator(head_);
    }

    template <typename value_type>
    typename list<value_type>::const_iterator list<value_type>::end() const {
        return const_iterator(end_);
    }
};