#ifndef S21_LIST_H
#define S21_LIST_H

#include "s21_list.h"
 
template <typename value_type>
list<value_type>::list {
        // headNode = nullptr;
        // teilNode = nullptr;
        // endNode = nullptr;
        // size = 0;
        // headNode->next = nullptr;
        // headNode->prev = nullptr;
        // teilNode->prev = nullptr;
        // teilNode->next = nullptr;
        headNode = nullptr;
        tailNode = nullptr;
        size = 0;

         if (endNode) {
    endNode->next_ = headNode;
    endNode->prev_ = tailNode;
    endNode->value_ = size();
    if (headNode) {
      headNode->prev = endNode;
    }
    if (tailNode) {
      tailNode->next = endNode;
    }
  }
}



























#endif  // S21_LIST_H