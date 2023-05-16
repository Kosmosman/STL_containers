#include <stack>

#include "test.h"

namespace s21 {
class S21StackTest : public testing::Test {
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

  s21::Stack<Example> s21_stack_emplace;
  s21::Stack<int> s21_empty;
  s21::Stack<char> s21_init_list{'c', 'b', 'a'};
  s21::Stack<int> s21_stack_for_copy{1, 1, 2, 3, 5, 8, 13};

  std::stack<int> std_empty;
  std::stack<Example> std_stack_emplace;
};

TEST_F(S21StackTest, DefaultConstructor) {
  EXPECT_EQ(s21_empty.size(), std_empty.size());
  EXPECT_EQ(s21_empty.empty(), std_empty.empty());
}

TEST_F(S21StackTest, InitializerListConstructor) {
  EXPECT_EQ(s21_init_list.size(), 3);
  EXPECT_EQ(s21_init_list.top(), 'a');
  s21_init_list.pop();
  EXPECT_EQ(s21_init_list.top(), 'b');
  s21_init_list.pop();
  EXPECT_EQ(s21_init_list.top(), 'c');
}

TEST_F(S21StackTest, InitializerListConstructorStd) {
  std::initializer_list<int> init_list = {1, 2, 3};
  s21::Stack<int> s21_stack{init_list};
  std::stack<int> std_stack{init_list};

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty() && !std_stack.empty()) {
    EXPECT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST_F(S21StackTest, CopyConstructor) {
  std::initializer_list<int> init_list_for_copy = {1, 1, 2, 3, 5, 8, 13};
  s21::Stack<int> s21_stack_for_copy{init_list_for_copy};
  std::stack<int> std_stack_for_copy{init_list_for_copy};

  s21::Stack<int> s21_stack(s21_stack_for_copy);
  std::stack<int> std_stack(std_stack_for_copy);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty() && !std_stack.empty()) {
    EXPECT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST_F(S21StackTest, MoveConstructor) {
  std::initializer_list<double> init_list_for_copy = {1231.4, 1.342, 3.23, 4.4};
  s21::Stack<double> s21_stack_for_move{init_list_for_copy};
  std::stack<double> std_stack_for_move{init_list_for_copy};

  s21::Stack<double> s21_stack(std::move(s21_stack_for_move));
  std::stack<double> std_stack(std::move(std_stack_for_move));
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty() && !std_stack.empty()) {
    EXPECT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }

  EXPECT_EQ(s21_stack_for_move.size(), std_stack_for_move.size());
}

TEST_F(S21StackTest, AssignmentOperatorMoving) {
  std::initializer_list<double> init_list_for_copy = {1231.4, 1.342, 3.23, 4.4};
  s21::Stack<double> s21_stack_for_move{init_list_for_copy};
  std::stack<double> std_stack_for_move{init_list_for_copy};

  s21::Stack<double> s21_stack = std::move(s21_stack_for_move);
  std::stack<double> std_stack = std::move(std_stack_for_move);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty() && !std_stack.empty()) {
    EXPECT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }

  EXPECT_EQ(s21_stack_for_move.size(), std_stack_for_move.size());
}

TEST_F(S21StackTest, Push) {
  s21_empty.push(123);
  std_empty.push(123);
  EXPECT_EQ(s21_empty.top(), std_empty.top());
  EXPECT_EQ(s21_empty.size(), std_empty.size());
  s21_empty.push(45322345);
  std_empty.push(45322345);
  EXPECT_EQ(s21_empty.top(), std_empty.top());
  EXPECT_EQ(s21_empty.size(), std_empty.size());
}

TEST_F(S21StackTest, Pop) {
  s21_empty.push(123);
  std_empty.push(123);
  s21_empty.push(45322345);
  std_empty.push(45322345);
  EXPECT_EQ(s21_empty.top(), std_empty.top());
  EXPECT_EQ(s21_empty.size(), std_empty.size());
  s21_empty.pop();
  std_empty.pop();
  EXPECT_EQ(s21_empty.top(), std_empty.top());
  EXPECT_EQ(s21_empty.size(), std_empty.size());
  s21_empty.pop();
  std_empty.pop();
  EXPECT_EQ(s21_empty.size(), std_empty.size());
}

TEST_F(S21StackTest, Swap) {
  std::initializer_list<int> init_list = {1, 1, 3, 6};
  std::initializer_list<int> init_list_for_swap = {1, 3, 5, 5, 6, 7};
  s21::Stack<int> s21_stack{init_list};
  s21::Stack<int> s21_stack_for_swap{init_list_for_swap};

  std::stack<int> std_stack{init_list};
  std::stack<int> std_stack_for_swap{init_list_for_swap};

  while (!s21_stack.empty() && !std_stack.empty()) {
    EXPECT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }

  while (!s21_stack_for_swap.empty() && !std_stack_for_swap.empty()) {
    EXPECT_EQ(s21_stack_for_swap.top(), std_stack_for_swap.top());
    s21_stack_for_swap.pop();
    std_stack_for_swap.pop();
  }
}

TEST_F(S21StackTest, EmplaceFront) {
  s21_stack_emplace.push(Example(1, 2));
  std_stack_emplace.push(Example(1, 2));
  EXPECT_EQ(s21_stack_emplace.size(), std_stack_emplace.size());
  EXPECT_EQ(s21_stack_emplace.top(), std_stack_emplace.top());
  s21_stack_emplace.emplace_front(4, 5);
  std_stack_emplace.emplace(4, 5);
  EXPECT_EQ(s21_stack_emplace.size(), std_stack_emplace.size());
  EXPECT_EQ(s21_stack_emplace.top(), std_stack_emplace.top());
}

}  // namespace s21