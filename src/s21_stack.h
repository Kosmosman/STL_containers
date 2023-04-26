#ifndef SRC_S21_STACK_H_
#define SRC_S21_STACK_H_

namespace s21 {
    template<typename T>
    class Stack{
        public:
            Stack();
        private:
            struct Node {
                T value;
                Node* next;
            };
            Node* head_;
    };
};

#endif // SRC_S21_STACK_H_