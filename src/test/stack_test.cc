#include "test.h"

TEST(StackTest, DefaultConstructor) {
    s21::Stack<int> stack;
    EXPECT_EQ(stack.size(), 0);
}

TEST(StackTest, InitializerListConstructor) {
    s21::Stack<char> stack = {'c', 'b', 'a'};
    EXPECT_EQ(stack.size(), 3);
    EXPECT_EQ(stack.top(), 'a');
    stack.pop();
    EXPECT_EQ(stack.top(), 'b');
    stack.pop();
    EXPECT_EQ(stack.top(), 'c');
}