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

TEST(QueueTest, BackConst) {
  s21::Queue<double> queue = {5.1, 324.1};
  EXPECT_DOUBLE_EQ(queue.back(), 324.1);
  queue.push(3243.12);
  EXPECT_DOUBLE_EQ(queue.back(), 3243.12);
}

TEST(QueueTest, Back) {
  s21::Queue<double> queue = {5.1, 3324.1};
  EXPECT_DOUBLE_EQ(queue.back(), 3324.1);
  queue.back() = 32.1;
  EXPECT_DOUBLE_EQ(queue.back(), 32.1);
}

TEST(QueueTest, Empty) {
  s21::Queue<double> queue_1;
  EXPECT_EQ(queue_1.empty(), true);

  s21::Queue<double> queue_2 = {5.1, 3324.1};
  EXPECT_EQ(queue_2.empty(), false);
}

TEST(QueueTest, Size) {
  s21::Queue<int> queue;
  EXPECT_EQ(queue.size(), 0);
  queue.push(13);
  queue.push(234);
  EXPECT_EQ(queue.size(), 2);
  queue.pop();
  EXPECT_EQ(queue.size(), 1);
  queue.pop();
  EXPECT_EQ(queue.size(), 0);
}

// TEST(QueueTest, Push) {

// }

// TEST(QueueTest, Pop) {

// }

// TEST(QueueTest, Swap) {

// }