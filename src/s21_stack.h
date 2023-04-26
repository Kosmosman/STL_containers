#ifndef SRC_S21_STACK_H_
#define SRC_S21_STACK_H_
// #include <iostream>
#include <iostream>


namespace s21 {
    template<typename T>
    class Stack{
        public:
            Stack();
            ~Stack();

            using value_type = T;
            using reference = T&;
            using const_reference = const T&;
            using size_type = size_t;

            void push(const_reference node);
            void pop();
            bool empty();
            size_type size();
            const_reference top();

        private:
            struct Node {
                T value;
                Node* next;
            };

            Node* head_;
            size_type size_;
    };
};
#include "s21_stack.tpp"
#endif // SRC_S21_STACK_H_