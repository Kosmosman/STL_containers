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
  s21::Queue<char> queue_1 = {'a', 'b', 'c', 'd'};
  s21::Queue<char> queue_2(queue_1);
  EXPECT_EQ(queue_2.front(), 'a');
  EXPECT_EQ(queue_2.back(), 'd');
  EXPECT_EQ(queue_2.size(), 4);
}

TEST(QueueTest, MoveConstructor) {
  s21::Queue<char> queue_1 = {'a', 'b', 'c', 'd'};
  s21::Queue<char> queue_2(std::move(queue_1));
  EXPECT_EQ(queue_2.front(), 'a');
  EXPECT_EQ(queue_2.back(), 'd');
  EXPECT_EQ(queue_2.size(), 4);

  EXPECT_EQ(queue_1.size(), 0);
}

TEST(QueueTest, AssignmentOperatorMoving) {
  s21::Queue<char> queue_1 = {'a', 'b', 'c', 'd'};
  s21::Queue<char> queue_2 = std::move(queue_1);
  EXPECT_EQ(queue_2.front(), 'a');
  EXPECT_EQ(queue_2.back(), 'd');
  EXPECT_EQ(queue_2.size(), 4);

  EXPECT_EQ(queue_1.size(), 0);
}

// TEST(QueueTest, TopElement) {

// }

// TEST(QueueTest, Empty) {

// }

// TEST(QueueTest, Size) {

// }

// TEST(QueueTest, Push) {

// }

// TEST(QueueTest, Pop) {

// }

// TEST(QueueTest, Swap) {

// }