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
            size_type size();

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