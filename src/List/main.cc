#include <iostream>
#include "s21_list.h"

int _main() {
    s21::list<int> test;
    //------------
//    std::list<int> testOriginal;
    for (const auto &item: test) {
        std::cout << item << " ";
    }
    return 0;
}
//template <class T>
//void print(const T& t) {
//    for (typename T::const_iterator it = t.begin(); it != t.end(); ++it)
//    {
//        std::cout << *it << " ";
//    }
//    std::cout << "\n";
//}
//template <class T>
//struct Node {
//private:
//    template<class Iter>
//    class NodeIterator{
//        friend class Node;
//    public:
//        typedef Iter iterator_type;
//        typedef std::input_iterator_tag iterator_category;
//        typedef iterator_type value_type;
//        typedef ptrdiff_t difference_type;
//        typedef iterator_type& reference;
////        typedef iterator_type& pointer;
//
//        iterator_type* value; // все что хронит у нас итератор это указатель на точто он указывает
//
//    private:
//        NodeIterator(Iter* p) : value(p) {} // иницилизирует значение которое в нутри находится
//    public:
//        NodeIterator(const  NodeIterator& it) : value(it.value) {}
//
//    };
//public:
//    T value;
//    std::unique_ptr<Node> left;
//    std::unique_ptr<Node> right;
//    Node* parent;
//
//    Node(const T& value,std::unique_ptr<Node> left,std::unique_ptr<Node> right, Node* parent) : value(value), left(std::move(left)), right(std::move(right)), parent(parent) {}
//    Node(const Node&) = delete;
//
//    typedef NodeIterator<Node> iterator;
//    typedef NodeIterator<const Node> const_iterator;
//
//    iterator begin();
//    iterator end();
//
//    const_iterator begin() const;
//    const_iterator end() const;
//};
////    std::string str{"Hello world\n"};
////
//////    for (auto it = str.begin(); it != str.end(); ++it)
//////    {
//////        std::cout << *it << std::endl;
//////    }
//////    // ----> тоже самое
//////    for (auto &&s : str) {
//////        std::cout << s << std::endl; // под капотом все сам сделает
//////    }
////         auto root = std::make_unique<Node<std::string>>("a1", nullptr, nullptr, nullptr);
////         root->left = std::make_unique<Node<std::string>>("b1", nullptr, nullptr, root.get());
////         root->right = std::make_unique<Node<std::string>>("b2", nullptr, nullptr, root.get());
////
////         auto b1 = root->left.get();
////         auto b2 = root->right.get();
////
////    b1->left = std::make_unique<Node<std::string>>("c1", nullptr, nullptr, b1);
////    b1->right = std::make_unique<Node<std::string>>("c2", nullptr, nullptr, b1);
////    b2->left = std::make_unique<Node<std::string>>("c3", nullptr, nullptr, b2);
////    b2->right = std::make_unique<Node<std::string>>("c4", nullptr, nullptr, b2);
////
////    auto c1 = b1->left.get();
////    auto c2 = b1->right.get();
////    auto c3 = b2->left.get();
////    auto c4 = b2->right.get();
////
////    std::cout << root->value << std::endl;
////    std::cout << b1->value << std::endl;
////    std::cout << b2->value << std::endl;
////    std::cout << c1->value << std::endl;
////    std::cout << c2->value << std::endl;
////    std::cout << c3->value << std::endl;
////    std::cout << c4->value << std::endl;
////    return 0;
////}