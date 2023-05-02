#include "test.h"

TEST(ArrayTest, DefaultConstructor) {
  s21::Array<int, 5> array;
  EXPECT_EQ(array.size(), 5);
}

TEST(ArrayTest, InitializerListConstructor) {
  s21::Array<int, 4> array_1 = {1, 2, 3, 4};
  EXPECT_EQ(array_1[0], 1);
  EXPECT_EQ(array_1[1], 2);
  EXPECT_EQ(array_1[2], 3);
  EXPECT_EQ(array_1[3], 4);

  s21::Array<int, 3> array_2 = {1, 2};
  EXPECT_EQ(array_2[0], 1);
  EXPECT_EQ(array_2[1], 2);
  EXPECT_EQ(array_2[2], 0);
}

TEST(ArrayTest, CopyConstructor) {
    s21::Array<int, 4> array_1 = {1, 2, 3, 4};
    s21::Array<int, 4> array_2(array_1);

    EXPECT_EQ(array_2.size(), 4);
    EXPECT_EQ(array_2[0], 1);
    EXPECT_EQ(array_2[1], 2);
    EXPECT_EQ(array_2[2], 3);
    EXPECT_EQ(array_2[3], 4);
}

TEST(ArrayTest, MoveConstructor) {
    s21::Array<int, 4> array_1 = {1, 2, 3, 4};
    s21::Array<int, 4> array_2(std::move(array_1));

    EXPECT_EQ(array_2.size(), 4);
    EXPECT_EQ(array_2[0], 1);
    EXPECT_EQ(array_2[1], 2);
    EXPECT_EQ(array_2[2], 3);
    EXPECT_EQ(array_2[3], 4);

    EXPECT_EQ(array_1.size(), 0);
}

TEST(ArrayTest, AssignmentOperatorMoving) {
    s21::Array<int, 4> array_1 = {1, 2, 3, 4};
    s21::Array<int, 4> array_2 = std::move(array_1);

    EXPECT_EQ(array_2.size(), 4);
    EXPECT_EQ(array_2[0], 1);
    EXPECT_EQ(array_2[1], 2);
    EXPECT_EQ(array_2[2], 3);
    EXPECT_EQ(array_2[3], 4);

    EXPECT_EQ(array_1.size(), 0);
}

TEST(ArrayTest, At) {
    s21::Array<int, 4> array = {1, 2, 3, 4};
    array.at(0) = 4;
    EXPECT_EQ(array[0], 4);
}

TEST(ArrayTest, AtThrow) {
    s21::Array<int, 4> array = {1, 2, 3, 4};

    EXPECT_THROW(array.at(-1) = 4, std::out_of_range);
}

// TEST(ArrayTest, FrontConst) {
//   s21::Queue<double> queue = {5.1};
//   EXPECT_DOUBLE_EQ(queue.front(), 5.1);
//   queue.pop();
//   queue.push(3243.12);
//   EXPECT_DOUBLE_EQ(queue.front(), 3243.12);
// }

// TEST(ArrayTest, Front) {
//   s21::Queue<double> queue = {5.1};
//   EXPECT_DOUBLE_EQ(queue.front(), 5.1);
//   queue.front() = 32.1;
//   EXPECT_DOUBLE_EQ(queue.front(), 32.1);
// }

// TEST(ArrayTest, BackConst) {
//   s21::Queue<double> queue = {5.1, 324.1};
//   EXPECT_DOUBLE_EQ(queue.back(), 324.1);
//   queue.push(3243.12);
//   EXPECT_DOUBLE_EQ(queue.back(), 3243.12);
// }

// TEST(ArrayTest, Back) {
//   s21::Queue<double> queue = {5.1, 3324.1};
//   EXPECT_DOUBLE_EQ(queue.back(), 3324.1);
//   queue.back() = 32.1;
//   EXPECT_DOUBLE_EQ(queue.back(), 32.1);
// }

// TEST(ArrayTest, Empty) {
//   s21::Queue<double> queue_1;
//   EXPECT_EQ(queue_1.empty(), true);

//   s21::Queue<double> queue_2 = {5.1, 3324.1};
//   EXPECT_EQ(queue_2.empty(), false);
// }

// TEST(ArrayTest, Size) {
//   s21::Queue<int> queue;
//   EXPECT_EQ(queue.size(), 0);
//   queue.push(13);
//   queue.push(234);
//   EXPECT_EQ(queue.size(), 2);
//   queue.pop();
//   EXPECT_EQ(queue.size(), 1);
//   queue.pop();
//   EXPECT_EQ(queue.size(), 0);
// }

// TEST(ArrayTest, Push) {
//   s21::Queue<int> queue;
//   queue.push(13);
//   EXPECT_EQ(queue.front(), 13);
//   EXPECT_EQ(queue.back(), 13);
//   queue.push(42);
//   EXPECT_EQ(queue.front(), 13);
//   EXPECT_EQ(queue.back(), 42);
// }

// TEST(ArrayTest, Pop) {
//   s21::Queue<int> queue = {1, 2, 3, 4, 5};
//   EXPECT_EQ(queue.front(), 1);
//   EXPECT_EQ(queue.back(), 5);
//   EXPECT_EQ(queue.size(), 5);
//   queue.pop();
//   EXPECT_EQ(queue.front(), 2);
//   EXPECT_EQ(queue.back(), 5);
//   EXPECT_EQ(queue.size(), 4);
// }

// TEST(ArrayTest, Swap) {
//   s21::Queue<int> queue_1 = {1, 2, 3};
//   s21::Queue<int> queue_2 = {4, 5};
//   queue_1.swap(queue_2);

//   EXPECT_EQ(queue_1.front(), 4);
//   EXPECT_EQ(queue_1.back(), 5);
//   EXPECT_EQ(queue_1.size(), 2);

//   EXPECT_EQ(queue_2.front(), 1);
//   EXPECT_EQ(queue_2.back(), 3);
//   EXPECT_EQ(queue_2.size(), 3);
// }