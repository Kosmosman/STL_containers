#include <iostream>
#include <queue>

#include "test.h"
// class TestQueue {
//  public:
//   s21::Queue<int> s21_queue_empty;
//   s21::Queue<int> s21_queue_three;

//   std::queue<int> std_queue_empty;
//   std::queue<int> std_queue_three;
// };

// TEST(Queue, default_constructor) {
//   TestQueue tester;
//   EXPECT_EQ(tester.s21_queue_empty.size(), tester.std_queue_empty.size());
//   EXPECT_EQ(tester.s21_queue_empty.empty(), tester.std_queue_empty.empty());
// }

// TEST(Queue, initializer_constructor) {
//   TestQueue tester;
//   while (!tester.s21_queue_three.empty()) {
//     EXPECT_EQ(tester.s21_queue_three.front(),
//     tester.std_queue_three.front()); tester.s21_queue_three.pop();
//     tester.std_queue_three.pop();
//   }
//   EXPECT_EQ(tester.s21_queue_three.size(), tester.std_queue_three.size());
//   EXPECT_EQ(tester.s21_queue_three.empty(), tester.std_queue_three.empty());
// }

// TEST(Queue, move_constructor) {
//   TestQueue tester;
//   s21::Queue<int> s21_queue_move(std::move(tester.s21_queue_three));
//   std::queue<int> std_queue_move(std::move(tester.std_queue_three));
//   while (!s21_queue_move.empty()) {
//     EXPECT_EQ(s21_queue_move.front(), std_queue_move.front());
//     s21_queue_move.pop();
//     std_queue_move.pop();
//   }
//   EXPECT_EQ(s21_queue_move.size(), std_queue_move.size());
//   EXPECT_EQ(s21_queue_move.empty(), std_queue_move.empty());
//   while (!tester.s21_queue_three.empty()) {
//     EXPECT_EQ(tester.s21_queue_three.front(),
//     tester.s21_queue_three.front()); tester.s21_queue_three.pop();
//     tester.std_queue_three.pop();
//   }
//   EXPECT_EQ(tester.s21_queue_three.size(), tester.std_queue_three.size());
//   EXPECT_EQ(tester.s21_queue_three.empty(), tester.std_queue_three.empty());
// }

// TEST(Queue, move_assigment) {
//   TestQueue tester;
//   s21::Queue<int> s21_queue_move{1, 2};
//   std::queue<int> std_queue_move;
//   std_queue_move.push(1);
//   std_queue_move.push(2);
//   s21_queue_move = std::move(tester.s21_queue_three);
//   std_queue_move = std::move(tester.std_queue_three);
//   while (!s21_queue_move.empty()) {
//     EXPECT_EQ(s21_queue_move.front(), std_queue_move.front());
//     s21_queue_move.pop();
//     std_queue_move.pop();
//   }
//   EXPECT_EQ(s21_queue_move.size(), std_queue_move.size());
//   EXPECT_EQ(s21_queue_move.empty(), std_queue_move.empty());
// }

// TEST(Queue, function_push) {
//   TestQueue tester;
//   for (int i = 0; i < 10; i++) {
//     tester.s21_queue_empty.push(i);
//     tester.std_queue_empty.push(i);
//   }
//   while (!tester.std_queue_empty.empty() && !tester.s21_queue_empty.empty())
//   {
//     EXPECT_EQ(tester.std_queue_empty.front(),
//     tester.s21_queue_empty.front()); EXPECT_EQ(tester.std_queue_empty.back(),
//     tester.s21_queue_empty.back()); tester.std_queue_empty.pop();
//     tester.s21_queue_empty.pop();
//   }
//   EXPECT_EQ(tester.std_queue_empty.empty(), tester.s21_queue_empty.empty());
// }

// TEST(Queue, function_pop) {
//   TestQueue tester;
//   for (int i = 0; i < 456; i++) {
//     tester.s21_queue_empty.push(i);
//     tester.std_queue_empty.push(i);
//   }
//   while (!tester.std_queue_empty.empty() && !tester.s21_queue_empty.empty())
//   {
//     EXPECT_EQ(tester.std_queue_empty.front(),
//     tester.s21_queue_empty.front()); EXPECT_EQ(tester.std_queue_empty.back(),
//     tester.s21_queue_empty.back()); tester.std_queue_empty.pop();
//     tester.s21_queue_empty.pop();
//   }
//   EXPECT_EQ(tester.std_queue_empty.empty(), tester.s21_queue_empty.empty());
// }

// TEST(Queue, simple_test) {
//   TestQueue tester;
//   tester.s21_queue_empty.push(1);
//   tester.s21_queue_empty.push(2);
//   tester.s21_queue_empty.push(2555);
//   tester.s21_queue_empty.push(365434);
//   tester.std_queue_empty.push(1);
//   tester.std_queue_empty.push(2);
//   tester.std_queue_empty.push(2555);
//   tester.std_queue_empty.push(365434);
//   while (!tester.std_queue_empty.empty() && !tester.s21_queue_empty.empty())
//   {
//     EXPECT_EQ(tester.std_queue_empty.front(),
//     tester.s21_queue_empty.front()); EXPECT_EQ(tester.std_queue_empty.back(),
//     tester.s21_queue_empty.back()); tester.std_queue_empty.pop();
//     tester.s21_queue_empty.pop();
//   }
//   EXPECT_EQ(tester.std_queue_empty.empty(), tester.s21_queue_empty.empty());
// }

// TEST(Queue, swap_test) {
//   std::queue<double> orig_queue1;
//   orig_queue1.push(2.55);
//   orig_queue1.push(3.55);
//   orig_queue1.push(222.55);
//   orig_queue1.push(984.55);
//   orig_queue1.push(123.55);
//   orig_queue1.push(0.55);
//   orig_queue1.push(-34.55);
//   std::queue<double> orig_queue2;
//   orig_queue2.push(342.22);
//   orig_queue2.push(355.01);
//   orig_queue2.push(123.99);
//   orig_queue2.push(888.34);
//   orig_queue2.push(-23.11);
//   orig_queue2.push(1002.88);
//   orig_queue2.push(1.55);
//   s21::Queue<double> my_queue1;
//   my_queue1.push(2.55);
//   my_queue1.push(3.55);
//   my_queue1.push(222.55);
//   my_queue1.push(984.55);
//   my_queue1.push(123.55);
//   my_queue1.push(0.55);
//   my_queue1.push(-34.55);
//   s21::Queue<double> my_queue2;
//   my_queue2.push(342.22);
//   my_queue2.push(355.01);
//   my_queue2.push(123.99);
//   my_queue2.push(888.34);
//   my_queue2.push(-23.11);
//   my_queue2.push(1002.88);
//   my_queue2.push(1.55);
//   orig_queue1.swap(orig_queue2);
//   my_queue1.swap(my_queue2);
//   while (!orig_queue1.empty() && !my_queue1.empty()) {
//     ASSERT_DOUBLE_EQ(orig_queue1.front(), my_queue1.front());
//     ASSERT_DOUBLE_EQ(orig_queue1.back(), my_queue1.back());
//     orig_queue1.pop();
//     my_queue1.pop();
//   }
//   while (!orig_queue2.empty() && !my_queue2.empty()) {
//     ASSERT_DOUBLE_EQ(orig_queue2.front(), my_queue2.front());
//     ASSERT_DOUBLE_EQ(orig_queue2.back(), my_queue2.back());
//     orig_queue2.pop();
//     my_queue2.pop();
//   }
//   ASSERT_EQ(orig_queue2.empty(), my_queue2.empty());
// }

// TEST(Queue, copy_constructor_test) {
//   s21::Queue<int> my_queue;
//   std::queue<int> orig_queue;
//   s21::Queue<int> my_queue2(my_queue);
//   std::queue<int> orig_queue2(orig_queue);
//   ASSERT_EQ(orig_queue2.empty(), my_queue2.empty());

//   std::queue<char> orig_q1;
//   orig_q1.push('a');
//   orig_q1.push('b');
//   orig_q1.push('c');
//   orig_q1.push('d');
//   s21::Queue<char> copy_q1;
//   copy_q1.push('a');
//   copy_q1.push('b');
//   copy_q1.push('c');
//   copy_q1.push('d');
//   std::queue<char> orig_q2(orig_q1);
//   s21::Queue<char> copy_q2(copy_q1);
//   ASSERT_EQ(orig_q2.size(), copy_q2.size());
//   while (!orig_q2.empty() && !copy_q2.empty()) {
//     ASSERT_EQ(orig_q2.front(), copy_q2.front());
//     ASSERT_EQ(orig_q2.back(), copy_q2.back());
//     orig_q2.pop();
//     copy_q2.pop();
//   }
// }

// TEST(Queue, move_constructor_test) {
//   std::queue<char> orig_q1;
//   orig_q1.push('a');
//   orig_q1.push('b');
//   orig_q1.push('c');
//   orig_q1.push('d');
//   s21::Queue<char> copy_q1;
//   copy_q1.push('a');
//   copy_q1.push('b');
//   copy_q1.push('c');
//   copy_q1.push('d');
//   std::queue<char> orig_q2(std::move(orig_q1));
//   s21::Queue<char> copy_q2(std::move(copy_q1));
//   ASSERT_EQ(orig_q1.size(), copy_q1.size());
//   ASSERT_EQ(orig_q2.size(), copy_q2.size());
//   while (!orig_q2.empty() && !copy_q2.empty()) {
//     ASSERT_EQ(orig_q2.front(), copy_q2.front());
//     ASSERT_EQ(orig_q2.back(), copy_q2.back());
//     orig_q2.pop();
//     copy_q2.pop();
//   }
// }

// TEST(Queue, move_operator_test) {
//   std::queue<char> orig_q1;
//   orig_q1.push('a');
//   orig_q1.push('b');
//   orig_q1.push('c');
//   orig_q1.push('d');
//   s21::Queue<char> copy_q1;
//   copy_q1.push('a');
//   copy_q1.push('b');
//   copy_q1.push('c');
//   copy_q1.push('d');
//   std::queue<char> orig_q2;
//   orig_q2.push('h');
//   s21::Queue<char> copy_q2{'h'};
//   EXPECT_EQ(orig_q1.size(), copy_q1.size());
//   EXPECT_EQ(orig_q2.size(), copy_q2.size());
//   orig_q2 = std::move(orig_q1);
//   copy_q2 = std::move(copy_q1);
//   EXPECT_EQ(orig_q1.size(), copy_q1.size());
//   EXPECT_EQ(orig_q2.size(), copy_q2.size());
//   while (!orig_q2.empty() && !copy_q2.empty()) {
//     EXPECT_EQ(orig_q2.front(), copy_q2.front());
//     EXPECT_EQ(orig_q2.back(), copy_q2.back());
//     orig_q2.pop();
//     copy_q2.pop();
//   }
// }

// TEST(Queue, emplace_test) {
//   std::queue<char> orig_q1;
//   orig_q1.push('a');
//   orig_q1.push('b');
//   orig_q1.push('c');
//   orig_q1.push('d');
//   orig_q1.emplace('p');
//   orig_q1.emplace('z');
//   orig_q1.emplace('i');
//   s21::Queue<char> copy_q1;
//   copy_q1.push('a');
//   copy_q1.push('b');
//   copy_q1.push('c');
//   copy_q1.push('d');
//   copy_q1.emplace_back('p');
//   copy_q1.emplace_back('z');
//   copy_q1.emplace_back('i');
//   while (!orig_q1.empty() && !copy_q1.empty()) {
//     EXPECT_EQ(orig_q1.front(), copy_q1.front());
//     EXPECT_EQ(orig_q1.back(), copy_q1.back());
//     orig_q1.pop();
//     copy_q1.pop();
//   }
//   EXPECT_EQ(orig_q1.size(), copy_q1.size());
// }

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

TEST(QueueTest, Push) {
  s21::Queue<int> queue;
  queue.push(13);
  EXPECT_EQ(queue.front(), 13);
  EXPECT_EQ(queue.back(), 13);
  queue.push(42);
  EXPECT_EQ(queue.front(), 13);
  EXPECT_EQ(queue.back(), 42);
}

TEST(QueueTest, Pop) {
  s21::Queue<int> queue = {1, 2, 3, 4, 5};
  EXPECT_EQ(queue.front(), 1);
  EXPECT_EQ(queue.back(), 5);
  EXPECT_EQ(queue.size(), 5);
  queue.pop();
  EXPECT_EQ(queue.front(), 2);
  EXPECT_EQ(queue.back(), 5);
  EXPECT_EQ(queue.size(), 4);
}

TEST(QueueTest, Swap) {
  s21::Queue<int> queue_1 = {1, 2, 3};
  s21::Queue<int> queue_2 = {4, 5};
  queue_1.swap(queue_2);

  EXPECT_EQ(queue_1.front(), 4);
  EXPECT_EQ(queue_1.back(), 5);
  EXPECT_EQ(queue_1.size(), 2);

  EXPECT_EQ(queue_2.front(), 1);
  EXPECT_EQ(queue_2.back(), 3);
  EXPECT_EQ(queue_2.size(), 3);
}

TEST(QueueTest, EmplaceBack) {
  class Example {
   public:
    Example() : x_(0), y_(0){};
    Example(int x, int y) : x_(x), y_(y){};
    int getX() { return x_; }
    int getY() { return y_; }

   private:
    int x_, y_;
  };

  s21::Queue<Example> queue;
  queue.push(Example(1, 2));
  queue.emplace_back(4, 5);

  EXPECT_EQ(queue.back().getX(), 4);
  EXPECT_EQ(queue.back().getY(), 5);
}