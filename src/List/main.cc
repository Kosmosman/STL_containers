#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include "s21_list.h"

int main() {

    s21::list<int> my_list1{1, 9999, 20000};
    my_list1.erase(my_list1.begin());

    std::list<int> std_list1{1, 9999, 20000};
    std_list1.erase(std_list1.begin());

    for (const auto &item: my_list1) {
        std::cout << item << " ";
    }
    std::cout  << "\n";
    for (const auto &item: std_list1) {
        std::cout << item << " ";
    }

    return 0;
}