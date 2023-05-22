#include <iostream>
#include "s21_list.h"

int main() {
    s21::list<int> test {1,3,4};


    //------------
//    s::list<int> testOriginal;
//    for (const auto &item: test) {
//        std::cout << item << " ";
//    }
//
//    auto begin = ыtest.begin();
//    auto end = test.end();

    s21::list<int>::ListIterator it;
    for (it = test.begin(); it != test.end(); ++it) {
        const auto& item = *it;
        std::cout << item << " ";
    }
    return 0;
}