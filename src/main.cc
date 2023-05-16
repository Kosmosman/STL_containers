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
  std::array<int, 5> ar1{1, 2};
  std::array<int, 5> ar2(std::move(ar1));
  std::cout << ar1.at(0) << std::endl;

  // std::cout << s21_const_front << std::endl;

  return 0;
}
