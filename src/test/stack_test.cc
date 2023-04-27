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

TEST(StackTest, CopyConstructor) {
    s21::Stack<double> stack_1 = {1231.4, 1.342, 3.23, 4.4};
    s21::Stack<double> stack_2(stack_1);
    EXPECT_EQ(stack_2.size(), 4);
    EXPECT_DOUBLE_EQ(stack_2.top(), 4.4);
    stack_2.pop();
    EXPECT_DOUBLE_EQ(stack_2.top(), 3.23);
    stack_2.pop();
    EXPECT_DOUBLE_EQ(stack_2.top(), 1.342);
    stack_2.pop();
    EXPECT_DOUBLE_EQ(stack_2.top(), 1231.4);
}

TEST(StackTest, MoveConstructor) {
    s21::Stack<double> stack_1 = {1231.4, 1.342, 3.23, 4.4};
    s21::Stack<double> stack_2(std::move(stack_1));
    EXPECT_EQ(stack_2.size(), 4);
    EXPECT_EQ(stack_1.size(), 0);

    EXPECT_DOUBLE_EQ(stack_2.top(), 4.4);
    stack_2.pop();
    EXPECT_DOUBLE_EQ(stack_2.top(), 3.23);
    stack_2.pop();
    EXPECT_DOUBLE_EQ(stack_2.top(), 1.342);
    stack_2.pop();
    EXPECT_DOUBLE_EQ(stack_2.top(), 1231.4);

}