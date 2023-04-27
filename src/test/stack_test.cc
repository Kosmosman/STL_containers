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

TEST(StackTest, AssignmentOperatorMoving) {
  s21::Stack<double> stack_1 = {1231.4, 1.342, 3.23, 4.4};
  s21::Stack<double> stack_2 = std::move(stack_1);
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

TEST(StackTest, TopElement) {
  s21::Stack<int> stack = {324, 232, 45};
  EXPECT_EQ(stack.top(), 45);
  stack.top() = 12;
  EXPECT_EQ(stack.top(), 12);
}

TEST(StackTest, Empty) {
  s21::Stack<int> stack;
  EXPECT_EQ(stack.empty(), true);
  stack.push(123);
  EXPECT_EQ(stack.empty(), false);
  stack.pop();
  EXPECT_EQ(stack.empty(), true);
}

TEST(StackTest, Size) {
  s21::Stack<int> stack = {1, 2, 431};
  EXPECT_EQ(stack.size(), 3);
  stack.pop();
  EXPECT_EQ(stack.size(), 2);
  stack.push(123);
  EXPECT_EQ(stack.size(), 3);
  stack.pop();
  EXPECT_EQ(stack.size(), 2);
  stack.pop();
  EXPECT_EQ(stack.size(), 1);
  stack.pop();
  EXPECT_EQ(stack.size(), 0);
}

TEST(StackTest, Push) {
  s21::Stack<int> stack = {1, 2, 431};
  stack.push(123);
  EXPECT_EQ(stack.top(), 123);
  EXPECT_EQ(stack.size(), 4);
}

TEST(StackTest, Pop) {
  s21::Stack<int> stack = {1123, 23, 431};
  stack.pop();
  EXPECT_EQ(stack.top(), 23);
  EXPECT_EQ(stack.size(), 2);
  stack.pop();
  EXPECT_EQ(stack.top(), 1123);
  EXPECT_EQ(stack.size(), 1);
  stack.pop();
  EXPECT_EQ(stack.size(), 0);
}

TEST(StackTest, Swap) {
  s21::Stack<int> stack_1 = {1123, 23, 431, 31};
  s21::Stack<int> stack_2 = {43, 12, 4};
  stack_1.swap(stack_2);
  EXPECT_EQ(stack_1.top(), 4);
  EXPECT_EQ(stack_1.size(), 3);
  stack_1.pop();
  EXPECT_EQ(stack_1.top(), 12);
  EXPECT_EQ(stack_1.size(), 2);
  stack_1.pop();
  EXPECT_EQ(stack_1.top(), 43);
  EXPECT_EQ(stack_1.size(), 1);

  EXPECT_EQ(stack_2.top(), 31);
  EXPECT_EQ(stack_2.size(), 4);
  stack_2.pop();
  EXPECT_EQ(stack_2.top(), 431);
  EXPECT_EQ(stack_2.size(), 3);
  stack_2.pop();
  EXPECT_EQ(stack_2.top(), 23);
  EXPECT_EQ(stack_2.size(), 2);
  stack_2.pop();
  EXPECT_EQ(stack_2.top(), 1123);
  EXPECT_EQ(stack_2.size(), 1);
}