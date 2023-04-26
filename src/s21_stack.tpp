
// это можно убрать
#include "s21_stack.h"

namespace s21 {
    template<typename T>
    stack<T>::stack() : head_(nullptr), size_(0) { }

    template<typename T>
    // почему тут тачки, а не стрелочки. Это разве нее ссылки?
    stack<T>::stack(const stack &s) : head_(nullptr), size_(0) {
        Node* tmp = s.head_;
        while(tmp) {
            push(tmp->value);
            tmp = tmp->next;
        }
    } 


    // или лучше swap?
    template<typename T>
    stack<T>::stack(stack &&s) noexcept : head_(s.head_), size_(s.size_) {
        s.head_ = nullptr;
        s.size_ = 0;
    }

    template<typename T>
    stack<T>::~stack() {
        Node* tmp = nullptr;
        while (head_ != nullptr) {
            tmp = head_;
            head_ = head_->next;
            delete tmp;
            tmp = nullptr;
        }
    }
    

    template<typename T>
    void stack<T>::push(const_reference value) {
        Node* node = new Node();
        node->value = value;
        node->next = head_;
        head_ = node;
        size_ += 1;
    }

    template<typename T>
    typename stack<T>::size_type stack<T>::size() { return size_; }
    
    template<typename T>
    bool stack<T>::empty() {return size_ == 0; }

    template<typename T>
    void stack<T>::pop() {
        if (head_) {
            Node *temp_node = head_;
            head_ = head_->next;
            delete temp_node;
            temp_node = nullptr;
            size_ -= 1;
        }
    }

    template<typename T>
    typename stack<T>::const_reference stack<T>::top() { return head_->value; }
    
    template<typename T>
    void stack<T>::swap(stack& other) {
        std::swap(head_, other.head_);
        std::swap(size_, other.size_);
    }

    template<typename T>
    // как перезаписать?
    stack<T>& stack<T>::operator=(stack &&s) {
        if (*this == s)
            return *this;
        

    }
};