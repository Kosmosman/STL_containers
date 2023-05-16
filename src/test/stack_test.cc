#include <stack>

#include "test.h"

// namespace s21 {
class S21StackTest : public testing::Test {
 protected:
  class Example {
   public:
    Example() : x_(0), y_(0){};
    Example(int x, int y) : x_(x), y_(y){};
    int getX() { return x_; }
    int getY() { return y_; }
    bool operator==(const Example& other) {
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
  // std::initializer_list<int> init_list_for_copy = {1, 1, 2, 3, 5, 8, 13};
  // std::stack<int> std_stack_for_copy{init_list_for_copy};
  //  public:
  //   S21StackTest() = default;
  // std::stack<char> std_init_list{'c', 'b', 'a'};
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

  // stack.push(Example(1, 2));
  // stack.emplace_front(4, 5);

  // EXPECT_EQ(stack.top().getX(), 4);
  // EXPECT_EQ(stack.top().getY(), 5);
}

// TEST(Stack, simple_test) {
//   s21::Stack<int> my_stack;
//   std::stack<int> orig_stack;
//   my_stack.push(1);
//   my_stack.push(2);
//   my_stack.push(2555);
//   my_stack.push(365434);
//   orig_stack.push(1);
//   orig_stack.push(2);
//   orig_stack.push(2555);
//   orig_stack.push(365434);
//   while (!orig_stack.empty() && !my_stack.empty()) {
//     ASSERT_EQ(orig_stack.top(), my_stack.top());
//     orig_stack.pop();
//     my_stack.pop();
//   }
//   ASSERT_EQ(orig_stack.empty(), my_stack.empty());
// }
// TEST(Stack, swap_test) {
//   std::stack<double> orig_stack1;
//   orig_stack1.push(2.55);
//   orig_stack1.push(3.55);
//   orig_stack1.push(222.55);
//   orig_stack1.push(984.55);
//   orig_stack1.push(123.55);
//   orig_stack1.push(0.55);
//   orig_stack1.push(-34.55);
//   std::stack<double> orig_stack2;
//   orig_stack2.push(342.22);
//   orig_stack2.push(355.01);
//   orig_stack2.push(123.99);
//   orig_stack2.push(888.34);
//   orig_stack2.push(-23.11);
//   orig_stack2.push(1002.88);
//   orig_stack2.push(1.55);
//   s21::Stack<double> my_stack1;
//   my_stack1.push(2.55);
//   my_stack1.push(3.55);
//   my_stack1.push(222.55);
//   my_stack1.push(984.55);
//   my_stack1.push(123.55);
//   my_stack1.push(0.55);
//   my_stack1.push(-34.55);
//   s21::Stack<double> my_stack2;
//   my_stack2.push(342.22);
//   my_stack2.push(355.01);
//   my_stack2.push(123.99);
//   my_stack2.push(888.34);
//   my_stack2.push(-23.11);
//   my_stack2.push(1002.88);
//   my_stack2.push(1.55);
//   orig_stack1.swap(orig_stack2);
//   my_stack1.swap(my_stack2);
//   while (!orig_stack1.empty() && !my_stack1.empty()) {
//     ASSERT_DOUBLE_EQ(orig_stack1.top(), my_stack1.top());
//     orig_stack1.pop();
//     my_stack1.pop();
//   }
//   while (!orig_stack2.empty() && !my_stack2.empty()) {
//     ASSERT_DOUBLE_EQ(orig_stack2.top(), my_stack2.top());
//     orig_stack2.pop();
//     my_stack2.pop();
//   }
//   ASSERT_EQ(orig_stack2.empty(), my_stack2.empty());
// }

// TEST(Stack, move_operator_test) {
//   std::stack<int> orig_stack1;
//   orig_stack1.push(55);
//   orig_stack1.push(555);
//   orig_stack1.push(5555);
//   orig_stack1.push(55555);
//   std::stack<int> orig_stack2;
//   orig_stack2.push(1);
//   orig_stack2.push(2);
//   orig_stack2 = std::move(orig_stack1);
//   s21::Stack<int> copy_stack1;
//   copy_stack1.push(55);
//   copy_stack1.push(555);
//   copy_stack1.push(5555);
//   copy_stack1.push(55555);
//   s21::Stack<int> copy_stack2{1, 2};
//   copy_stack2 = std::move(copy_stack1);
//   while (!orig_stack2.empty() && !copy_stack2.empty()) {
//     ASSERT_EQ(orig_stack2.top(), copy_stack2.top());
//     orig_stack2.pop();
//     copy_stack2.pop();
//   }
//   ASSERT_EQ(orig_stack1.size(), copy_stack1.size());
// }

// TEST(Stack, emplace_test) {
//   std::stack<int> orig_stack1;
//   orig_stack1.push(55);
//   orig_stack1.push(555);
//   orig_stack1.push(5555);
//   orig_stack1.push(55555);
//   orig_stack1.emplace(345);
//   orig_stack1.emplace(234);
//   orig_stack1.emplace(889);
//   s21::Stack<int> copy_stack1;
//   copy_stack1.push(55);
//   copy_stack1.push(555);
//   copy_stack1.push(5555);
//   copy_stack1.push(55555);
//   copy_stack1.emplace_front(345);
//   copy_stack1.emplace_front(234);
//   copy_stack1.emplace_front(889);
//   while (!orig_stack1.empty() && !copy_stack1.empty()) {
//     ASSERT_EQ(orig_stack1.top(), copy_stack1.top());
//     orig_stack1.pop();
//     copy_stack1.pop();
//   }
//   ASSERT_EQ(orig_stack1.size(), copy_stack1.size());
// }
