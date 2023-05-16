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
  s21::Queue<int> s21_queue_empty;
  s21_queue_empty.push(1);
  s21::Queue<int>::const_reference s21_const_front =
      static_cast<s21::Queue<int>::const_reference>(s21_queue_empty.front());

  int arr[s21_const_front];
  arr[0] = 3;
  std::cout << arr[0] << std::endl;

  std::cout << s21_const_front << std::endl;

  return 0;
}
