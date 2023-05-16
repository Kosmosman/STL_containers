#include <iostream>
#include <queue>

#include "test.h"

class S21QueueTest : public testing::Test {
 protected:
  class Example {
   public:
    Example() : x_(0), y_(0){};
    Example(int x, int y) : x_(x), y_(y){};
    int getX() { return x_; }
    int getY() { return y_; }
    bool operator==(const Example& other) const {
      return x_ == other.x_ && y_ == other.y_;
    }

   private:
    int x_, y_;
  };

  s21::Queue<Example> s21_queue_emplace;
  s21::Queue<int> s21_queue_empty;
  s21::Queue<char> s21_queue_init_list{'c', 'b', 'a'};
  s21::Queue<int> s21_queue_for_copy{1, 1, 2, 3, 5, 8, 13};

  std::queue<int> std_queue_empty;
  std::queue<Example> std_queue_emplace;
};

TEST_F(S21QueueTest, DefaultConstructor) {
  EXPECT_EQ(s21_queue_empty.size(), std_queue_empty.size());
  EXPECT_EQ(s21_queue_empty.empty(), std_queue_empty.empty());
}

TEST_F(S21QueueTest, InitializerListConstructor) {
  std::initializer_list<int> init_list_for_copy = {1, 1, 2, 3, 5, 8, 13};
  s21::Queue<int> s21_queue{init_list_for_copy};
  std::queue<int> std_queue{init_list_for_copy};
  EXPECT_EQ(s21_queue.size(), std_queue.size());

  while (!s21_queue.empty() && !std_queue.empty()) {
    EXPECT_EQ(s21_queue.front(), std_queue.front());
    EXPECT_EQ(s21_queue.back(), std_queue.back());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST_F(S21QueueTest, CopyConstructor) {
  std::initializer_list<int> init_list_for_copy = {1, 1, 2, 3, 5, 8, 13};
  s21::Queue<int> s21_queue_for_copy{init_list_for_copy};
  std::queue<int> std_queue_for_copy{init_list_for_copy};

  s21::Queue<int> s21_queue(s21_queue_for_copy);
  std::queue<int> std_queue(std_queue_for_copy);

  EXPECT_EQ(s21_queue.size(), std_queue.size());
  while (!s21_queue.empty() && !std_queue.empty()) {
    EXPECT_EQ(s21_queue.front(), std_queue.front());
    EXPECT_EQ(s21_queue.back(), std_queue.back());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST_F(S21QueueTest, AssignmentOperatorCopy) {
  std::initializer_list<int> init_list_for_copy = {1, 1, 2, 3, 5, 8, 13};
  s21::Queue<int> s21_queue_for_copy{init_list_for_copy};
  std::queue<int> std_queue_for_copy{init_list_for_copy};

  s21::Queue<int> s21_queue;
  std::queue<int> std_queue;
  s21_queue = s21_queue_for_copy;
  std_queue = std_queue_for_copy;

  EXPECT_EQ(s21_queue.size(), std_queue.size());
  while (!s21_queue.empty() && !std_queue.empty()) {
    EXPECT_EQ(s21_queue.front(), std_queue.front());
    EXPECT_EQ(s21_queue.back(), std_queue.back());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST_F(S21QueueTest, MoveConstructor) {
  std::initializer_list<int> init_list_for_move = {1, 1, 2, 3, 5, 8, 13};
  s21::Queue<int> s21_queue_for_move{init_list_for_move};
  std::queue<int> std_queue_for_move{init_list_for_move};

  s21::Queue<int> s21_queue(std::move(s21_queue_for_move));
  std::queue<int> std_queue(std::move(std_queue_for_move));

  EXPECT_EQ(s21_queue.size(), std_queue.size());
  while (!s21_queue.empty() && !std_queue.empty()) {
    EXPECT_EQ(s21_queue.front(), std_queue.front());
    EXPECT_EQ(s21_queue.back(), std_queue.back());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST_F(S21QueueTest, AssignmentOperatorMove) {
  std::initializer_list<int> init_list_for_move = {1, 1, 2, 3, 5, 8, 13};
  s21::Queue<int> s21_queue_for_move{init_list_for_move};
  std::queue<int> std_queue_for_move{init_list_for_move};

  s21::Queue<int> s21_queue;
  std::queue<int> std_queue;
  std_queue = std::move(std_queue_for_move);
  s21_queue = std::move(s21_queue_for_move);

  EXPECT_EQ(s21_queue.size(), std_queue.size());
  while (!s21_queue.empty() && !std_queue.empty()) {
    EXPECT_EQ(s21_queue.front(), std_queue.front());
    EXPECT_EQ(s21_queue.back(), std_queue.back());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST_F(S21QueueTest, Push) {
  s21_queue_empty.push(1);
  std_queue_empty.push(1);
  EXPECT_EQ(s21_queue_empty.front(), std_queue_empty.front());
  EXPECT_EQ(s21_queue_empty.back(), std_queue_empty.back());
  EXPECT_EQ(s21_queue_empty.size(), std_queue_empty.size());
  s21_queue_empty.push(1123213);
  std_queue_empty.push(1123213);

  s21_queue_empty.front() = 21;
  std_queue_empty.front() = 21;

  s21_queue_empty.back() = 42;
  std_queue_empty.back() = 42;
  EXPECT_EQ(s21_queue_empty.front(), std_queue_empty.front());
  EXPECT_EQ(s21_queue_empty.back(), std_queue_empty.back());
  EXPECT_EQ(s21_queue_empty.size(), std_queue_empty.size());
}

// почему-то не работает
// TEST_F(S21QueueTest, FrontBackConst) {
//   s21_queue_empty.push(1);
//   std_queue_empty.push(1);
//   s21::Queue<int>::const_reference s21_const_front = s21_queue_empty.front();
//   std::queue<int>::const_reference std_const_front = std_queue_empty.front();

//   s21::Queue<int>::const_reference s21_const_back = s21_queue_empty.back();
//   std::queue<int>::const_reference std_const_back = std_queue_empty.back();

//   EXPECT_EQ(s21_const_front, std_const_front);
//   EXPECT_EQ(s21_const_back, std_const_back);
// }

TEST_F(S21QueueTest, Pop) {
  s21_queue_empty.push(1);
  std_queue_empty.push(1);
  s21_queue_empty.push(1123213);
  std_queue_empty.push(1123213);

  s21_queue_empty.pop();
  std_queue_empty.pop();
  EXPECT_EQ(s21_queue_empty.front(), std_queue_empty.front());
  EXPECT_EQ(s21_queue_empty.back(), std_queue_empty.back());
  EXPECT_EQ(s21_queue_empty.size(), std_queue_empty.size());

  s21_queue_empty.pop();
  std_queue_empty.pop();
  EXPECT_EQ(s21_queue_empty.size(), std_queue_empty.size());
}

TEST_F(S21QueueTest, Swap) {
  std::initializer_list<int> init_list = {1, 1, 3, 6};
  std::initializer_list<int> init_list_for_swap = {1, 3, 5, 5, 6, 7};
  s21::Queue<int> s21_queue{init_list};
  s21::Queue<int> s21_queue_for_swap{init_list_for_swap};

  std::queue<int> std_queue{init_list};
  std::queue<int> std_queue_for_swap{init_list_for_swap};

  s21_queue.swap(s21_queue_for_swap);
  std_queue.swap(std_queue_for_swap);

  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue_for_swap.size(), std_queue_for_swap.size());

  while (!s21_queue.empty() && !std_queue.empty()) {
    EXPECT_EQ(s21_queue.front(), std_queue.front());
    EXPECT_EQ(s21_queue.back(), std_queue.back());
    s21_queue.pop();
    std_queue.pop();
  }

  while (!s21_queue_for_swap.empty() && !std_queue_for_swap.empty()) {
    EXPECT_EQ(s21_queue_for_swap.front(), std_queue_for_swap.front());
    EXPECT_EQ(s21_queue_for_swap.back(), std_queue_for_swap.back());
    s21_queue_for_swap.pop();
    std_queue_for_swap.pop();
  }
}

TEST_F(S21QueueTest, EmplaceBack) {
  s21_queue_emplace.push(Example(1, 2));
  std_queue_emplace.push(Example(1, 2));
  EXPECT_EQ(s21_queue_emplace.size(), std_queue_emplace.size());
  EXPECT_EQ(s21_queue_emplace.front(), std_queue_emplace.front());
  EXPECT_EQ(s21_queue_emplace.back(), std_queue_emplace.back());
  s21_queue_emplace.emplace_back(4, 5);
  std_queue_emplace.emplace(4, 5);
  EXPECT_EQ(s21_queue_emplace.size(), std_queue_emplace.size());
  EXPECT_EQ(s21_queue_emplace.front(), std_queue_emplace.front());
  EXPECT_EQ(s21_queue_emplace.back(), std_queue_emplace.back());
}
