#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include "s21_list.h"

int main() {
//    s21::list<int> test {1, 2}; /// TODO error

    s21::list<int> my_list{1, 2, 3};
////    std::list<int> std_list;
////    std::list<int> std_list_copy(std_list);
//    s21::list<int>::ListIterator itt = my_list.begin();


//    std::list<int> std_list{1, 2, 4};
//    std::list<int> std_list2{23232323};
    s21::list<int> std_list_copy(my_list);
    for (const auto &item: std_list_copy) {
        std::cout << item << " ";
    }
//
//    my_list.insert(itt, 10);

//    for (const auto &item:std_list) {
//
//        std::cout << item << " ";
//    }


//    s21::list<int>::ListIterator it;
//    for (it = my_list.begin(); it != my_list.end(); ++it) {
//        const auto& item = *it;
//        std::cout << item << " ";
//    }
    return 0;
}