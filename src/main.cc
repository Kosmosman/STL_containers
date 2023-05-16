// #include <iostream>
#include <Stack>
#include <array>
#include <iostream>
#include <ostream>
#include <queue>
#include <set>
#include <vector>

#include "s21_array.h"
#include "s21_queue.h"
#include "s21_stack.h"

class Example {
 public:
  Example() : x_(0), y_(0){};
  Example(int x, int y) : x_(x), y_(y){};
  int getX() { return x_; }
  int getY() { return y_; }

 private:
  int x_, y_;
};

int main() {
  // std::stack<int> stack;
  std::vector<int> vector{1, 2, 3};
  std::cout << vector.front() << std::endl;

  return 0;
}
