// #include <iostream>
#include "s21_stack.h"
#include <stack>

int main() {
    // s21::stack<int>* st = new s21::stack<int>();
    s21::stack<int> stack;

    stack.push(4);
    stack.push(5);
    stack.push(324);
    // stack.top() = 4;
    // std::cout << stack.top();

    s21::stack<int> stack_2(stack);
    std::cout << stack_2.size();

    // stack_2.push(4);
    // stack_2.push(5);
    
    // stack.swap(stack_2);
    // std::cout << stack.top();
    // std::stack<int> example;
    // example.push(4);
    // // std::cout << example.size();
    // example.top() = 10;
    // std::cout << example.top();
    return 0;
}


// 