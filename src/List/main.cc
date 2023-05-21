#include <iostream>
#include "s21_list.h"

int main() {
    s21::list<int> test;
    //------------
//    std::list<int> testOriginal;
    for (const auto &item: test) {
        std::cout << item << " ";
    }
    return 0;
}