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

TEST(QueueTest, FrontConst) {
  s21::Queue<double> queue = {5.1};
  EXPECT_DOUBLE_EQ(queue.front(), 5.1);
  queue.pop();
  queue.push(3243.12);
  EXPECT_DOUBLE_EQ(queue.front(), 3243.12);
}

TEST(QueueTest, Front) {
  s21::Queue<double> queue = {5.1};
  EXPECT_DOUBLE_EQ(queue.front(), 5.1);
  queue.front() = 32.1;
  EXPECT_DOUBLE_EQ(queue.front(), 32.1);
}

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