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

TEST(ArrayTest, Operator) {
  s21::Array<int, 4> array = {1, 2, 3, 4};
  array[0] = 32344;
  EXPECT_EQ(array.at(0), 32344);
}

TEST(ArrayTest, Front) {
  s21::Array<int, 4> array = {1, 2, 3, 4};
  EXPECT_EQ(array.front(), 1);
}

TEST(ArrayTest, Back) {
  s21::Array<int, 4> array = {1, 2, 3, 4};
  EXPECT_EQ(array.back(), 4);
}

TEST(ArrayTest, Data) {
  s21::Array<int, 4> array = {1, 2, 3, 4};
  EXPECT_EQ(*array.data(), 1);
}

TEST(ArrayTest, Begin) {
  s21::Array<int, 4> array = {1, 2, 3, 4};
  EXPECT_EQ(*array.begin(), 1);
}

TEST(ArrayTest, End) {
  s21::Array<int, 4> array = {1, 2, 3, 4};
  EXPECT_EQ(array.end(), array.begin() + 4);
}

TEST(ArrayTest, NotEmpty) {
  s21::Array<int, 4> array = {1, 2, 3, 4};
  EXPECT_EQ(array.empty(), false);
}

TEST(ArrayTest, Empty) {
  s21::Array<int, 0> array;
  EXPECT_EQ(array.empty(), true);
}

TEST(ArrayTest, Size) {
  s21::Array<int, 4> array_1 = {1, 2, 3, 4};
  EXPECT_EQ(array_1.size(), 4);

  s21::Array<int, 0> array_2;
  EXPECT_EQ(array_2.size(), 0);
}

TEST(ArrayTest, MaxSize) {
  s21::Array<int, 4> array_1 = {1, 2, 3, 4};
  EXPECT_EQ(array_1.max_size(), 4);

  s21::Array<int, 0> array_2;
  EXPECT_EQ(array_2.max_size(), 0);
}

TEST(ArrayTest, Swap) {
  s21::Array<int, 4> array_1 = {1, 2, 3, 4};
  s21::Array<int, 4> array_2 = {11, 12, 13, 14};
  array_1.swap(array_2);

  EXPECT_EQ(array_1[0], 11);
  EXPECT_EQ(array_1[1], 12);
  EXPECT_EQ(array_1[2], 13);
  EXPECT_EQ(array_1[3], 14);

  EXPECT_EQ(array_2[0], 1);
  EXPECT_EQ(array_2[1], 2);
  EXPECT_EQ(array_2[2], 3);
  EXPECT_EQ(array_2[3], 4);
}

TEST(ArrayTest, Fill) {
  s21::Array<int, 4> array = {1, 2, 3, 4};
  array.fill(21);

  EXPECT_EQ(array[0], 21);
  EXPECT_EQ(array[1], 21);
  EXPECT_EQ(array[2], 21);
  EXPECT_EQ(array[3], 21);
}