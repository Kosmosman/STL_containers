

namespace s21 {
    template<typename T>
    Stack<T>::Stack(): head_(nullptr) { }

    template<typename T>
    Stack<T>::~Stack() { head_ = nullptr; }

    template<typename T>
    void Stack<T>::push(const_reference value) {
        Node* temp_stack = new Node();
        temp_stack->value = value;
        std::cout << value;
    }
    
};
