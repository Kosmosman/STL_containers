#ifndef S21_LIST_H
#define S21_LIST_H

#include <iostream>
#include <limits>
#include <initializer_list>

namespace s21 {

    template <typename T>
    class list {
    public:
        class ListIterator;
        class ListConstIterator;
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using size_type = std::size_t;
        using iterator = ListIterator;
        using const_iterator = ListConstIterator;

    private:
        struct Node {
            value_type value_;
            Node* prev_;
            Node* next_;

            Node(const value_type& value)
                    : value_(value), prev_(nullptr), next_(nullptr) {}
        };

        Node* head_;
        Node* tail_;
        Node* end_;
        size_type size_;

    public:
        list();
        list(size_type n);
        list(std::initializer_list<value_type> const& items);
        list(const list& l);
        list(list&& l);
//        ~list();
        list& operator=(list&& l);
        list& operator=(const list& l);

        const_reference front();
        const_reference back();
//
        bool empty();
        size_type size();
//        size_type max_size();
//
        void clear();
        void push_back(const_reference value);
        void pop_back();
        void push_front(const_reference value);
        void pop_front();
        void swap(list& other);
//        void merge(list& other);
//        void reverse();
//        void unique();
//        void sort();

        class ListIterator {
        public:
            ListIterator() { ptr_ = nullptr; }
            ListIterator(Node* ptr) : ptr_(ptr){};

            reference operator*();

            ListIterator operator++(int);

            ListIterator operator--(int);

            ListIterator& operator++();

            ListIterator& operator--();

            bool operator==(ListIterator other);
            bool operator!=(ListIterator other);

        private:
            Node* ptr_ = nullptr;
            friend class list<T>;
        };

        class ListConstIterator : public ListIterator {
        public:
            ListConstIterator(ListIterator other) : ListIterator(other) {}
            const_reference operator*() const;
        };

        ListIterator begin();
        ListIterator end();
        ListConstIterator begin() const;
        ListConstIterator end() const;

        ListIterator insert(ListIterator pos, const_reference value);
        void erase(ListIterator pos);
//        void splice(ListConstIterator pos, list& other);
//// доп method
     void setNewValueForList(Node* active, Node* add);
     void installationInBlankList(Node* add);
     void installationNotInBlankList(Node* active, Node* add);
     void change_end();
    };
}
#include "s21_list.tpp"
#endif  // S21_LIST_H