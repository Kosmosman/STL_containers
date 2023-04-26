
// это можно убрать
#include "s21_stack.h"

namespace s21 {
    template<typename T>
    Stack<T>::Stack(): head_(nullptr), size_(0) { }

    template<typename T>
    Stack<T>::~Stack() {
        // дописать полное очищение стека
        head_ = nullptr;
    }

    template<typename T>
    void Stack<T>::push(const_reference value) {
        Node* node = new Node();
        node->value = value;
        node->next = head_;
        head_ = node;
        size_ += 1;

        // std::cout << value;
    }

    template<typename T>
    typename Stack<T>::size_type Stack<T>::size() { return size_; }
    
    template<typename T>
    bool Stack<T>::empty() {return size_ == 0; }

    template<typename T>
    void Stack<T>::pop() {
        if (head_) {
            Node *temp_node = head_;
            head_ = head_->next;
            delete temp_node;
            temp_node = nullptr;
            size_ -= 1;
        }
    }
};