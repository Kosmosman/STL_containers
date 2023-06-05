#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include "s21_list.h"

int main() {

    s21::list<int> my_list1{1, 20000, 666, 3, 4, 1, 2, 3, 4, 5, 6, 7, 8};
    s21::list<int> my_list2{15000, 154, 124, 30000};
    my_list1.merge(my_list2);
    my_list1.sort();

//    std::list<int> my_list3{1, 20000, 666};
//    std::list<int> my_list4{15000, 154, 124, 30000};
////    my_list3.merge(my_list2);
//    my_list3.merge(my_list4);


//    for (const auto &item: my_list1) {
//        std::cout << item << " ";
//    }
    std::cout  << "\n";
    for (const auto &item: my_list1) {
        std::cout << item << " ";
    }

    return 0;
}