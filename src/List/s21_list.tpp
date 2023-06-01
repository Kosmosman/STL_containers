namespace s21 {

//// Constructs
    template <typename value_type>
    list<value_type>::list() : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
        std::cout<<"test";
        end_ = new Node(size_);
        change_end();
    }

    template <typename value_type>
    list<value_type>::list(size_type n)
            : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
        std::cout<<"test2 = size list: ";
        end_ = new Node(size_);
//        for (size_type i = 0; i < n; ++i) { //// TODO можно так
//            push_back(value_type());
//        }
        const_reference val = value_type();
        for (size_type i = 0; i < n; ++i) {
            insert(end(), val);//// TODO или так
        }
//        change_end();
    }
    template <typename value_type>
    list<value_type>::list(std::initializer_list<value_type> const& items)
            : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
        std::cout<<"test initializer_list  ";
        end_ = new Node(size_);
        for (const auto& item : items) {
            push_back(item);
            change_end();
        }
    }

    template <typename value_type>
    list<value_type>::list(const list& l)
            : head_(nullptr), tail_(nullptr), end_(nullptr), size_(0) {
        std::cout<<"test list copy construct  ";
        end_ = new Node(size_); ///// TODO требует рефакторинга раскидать на методы
        Node* current = l.head_;
        for (size_type i = 0; i != l.size_; i++) {
            push_back(current->value_);
            current = current->next_;
        }
//        *this = l;
/*        std::copy(l.begin(), l.end(), begin());*/
    }
    template <typename value_type>   //TODO не работает надо исправить
    list<value_type>::list(list&& l) {
//        *this = std::move(l);
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
    list<value_type>& list<value_type>::operator=(const list& l) {
        if (this == &l) throw std::out_of_range("Coping the same list is forbidden!");
        clear();
        for (auto it = l.begin(); it != l.end(); ++it) this->push_back(*it);
        return *this;
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
        //// TODO нужна реализация
        Node* node = pos.ptr_;

        if (node == nullptr || node == end_) {
            throw std::invalid_argument("Invalid argument"); // Invalid position or end iterator, do nothing TODO исправить на throw
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
    void list<value_type>::change_end() {
        if (end_) {
            end_->next_ = head_;
            end_->prev_ = tail_;
            end_->value_ = size();
//            head_ ? head_->prev_ = end_ : head_; // void();
            if (head_) {
                head_->prev_ = end_;
            }
//            tail_ ? tail_->next_ = end_ : head_; // void();
                        if (tail_) {
                tail_->next_ = end_;
            }
        }
    }
//    template <typename value_type>
//    void list<value_type>::change_end() {
//        if (end_) {
//            end_->next_ = head_;
//            end_->prev_ = tail_;
//            head_ ? head_->prev_ = end_ : void();  // Using ternary operator
//            tail_ ? tail_->next_ = end_ : void();  // Using ternary operator
//            end_->value_ = size();
//        }
//    }


//// push`s
    template <typename value_type> //// TODO проверить method на тестах
    void list<value_type>::push_back(const_reference value) {
        insert(end(), value);
    }

    //// insert & erase

    template <typename value_type> //// TODO проверить method на тестах
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