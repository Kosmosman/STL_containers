#include "test.h"

TEST(QueueTest, DefaultConstructor) {
  s21::Queue<int> queue;
  EXPECT_EQ(queue.size(), 0);
}

TEST(QueueTest, InitializerListConstructor) {
  s21::Queue<char> queue = {'a', 'b', 'c', 'd'};
  EXPECT_EQ(queue.front(), 'a');
  EXPECT_EQ(queue.back(), 'd');
  EXPECT_EQ(queue.size(), 4);
}

TEST(QueueTest, CopyConstructor) {

}

TEST(QueueTest, MoveConstructor) {

}

TEST(QueueTest, AssignmentOperatorMoving) {

}

TEST(QueueTest, TopElement) {

}

TEST(QueueTest, Empty) {

}

TEST(QueueTest, Size) {

}

TEST(QueueTest, Push) {

}

TEST(QueueTest, Pop) {

}

TEST(QueueTest, Swap) {

}