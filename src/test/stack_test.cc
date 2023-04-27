#include "test.h"

TEST(StackTest, DefaultConstructor) {
    s21::Stack<int> stack;
    EXPECT_EQ(stack.size(), 0);
}

// TEST(StackTest, DefaultConstructor) {
//     s21::Stack<int> stack;
//     EXPECT_EQ(stack.size(), 0);
// }