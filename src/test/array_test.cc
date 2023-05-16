#include <array>

#include "test.h"

class TestArray {
 public:
  s21::Array<int, 0> s21_array_empty;
  s21::Array<int, 3> copy_array{234, 21, 11};
  s21::Array<char, 0> copy_ar1;
  s21::Array<double, 5> copy_array1{2.5, 3.4, 255.3, 1.2, 0.5};
  s21::Array<double, 5> copy_array2{-5.3, 1.18, -4.3, 255.34, 1.23};

  std::array<int, 0> std_array_empty;
  std::array<int, 3> orig_array{234, 21, 11};
  std::array<char, 0> orig_ar1;
  std::array<double, 5> orig_array1{2.5, 3.4, 255.3, 1.2, 0.5};
  std::array<double, 5> orig_array2{-5.3, 1.18, -4.3, 255.34, 1.23};
};

TEST(Array, constructor_default) {
  TestArray tester;
  EXPECT_EQ(tester.s21_array_empty.size(), tester.std_array_empty.size());
  EXPECT_EQ(tester.s21_array_empty.empty(), tester.std_array_empty.empty());
}

TEST(Array, constructor_initializer) {
  TestArray tester;
  EXPECT_EQ(tester.copy_array1[1], tester.orig_array1[1]);
  EXPECT_EQ(tester.copy_array1.front(), tester.orig_array1.front());
  EXPECT_EQ(tester.copy_array1.back(), tester.orig_array1.back());
  EXPECT_EQ(tester.copy_array1.size(), tester.orig_array1.size());
  EXPECT_EQ(tester.copy_array1.empty(), tester.orig_array1.empty());
}

TEST(Array, constructor_copy_empty) {
  TestArray tester;
  s21::Array<int, 0> s21_array_copy(tester.s21_array_empty);
  std::array<int, 0> std_array_copy(tester.std_array_empty);
  EXPECT_EQ(s21_array_copy.size(), std_array_copy.size());
  EXPECT_EQ(s21_array_copy.empty(), std_array_copy.empty());
}

TEST(Array, simple_test) {
  TestArray logger;
  for (int i{}; i < 3; i++)
    ASSERT_EQ(logger.orig_array.at(i), logger.copy_array.at(i));
  ASSERT_EQ(logger.orig_array.size(), logger.copy_array.size());
  ASSERT_EQ(logger.orig_array.max_size(), logger.copy_array.max_size());
  ASSERT_EQ(logger.orig_ar1.empty(), logger.copy_ar1.empty());
}
TEST(Array, swap_test) {
  TestArray logger;
  logger.orig_array1.swap(logger.orig_array2);
  logger.copy_array1.swap(logger.copy_array2);
  for (int i{}; i < 5; i++) {
    ASSERT_DOUBLE_EQ(logger.orig_array1[i], logger.copy_array1[i]);
    ASSERT_DOUBLE_EQ(logger.orig_array2[i], logger.copy_array2[i]);
  }
  ASSERT_EQ(logger.orig_array1.size(), logger.copy_array1.size());
  ASSERT_EQ(logger.orig_array2.max_size(), logger.copy_array2.max_size());
  ASSERT_EQ(logger.orig_array1.front(), logger.copy_array1.front());
  ASSERT_EQ(logger.orig_array2.front(), logger.copy_array2.front());
  ASSERT_EQ(logger.orig_array1.back(), logger.copy_array1.back());
  ASSERT_EQ(logger.orig_array2.back(), logger.copy_array2.back());
}

TEST(Array, copy_constructor_test) {
  std::array<int, 3> orig_array3{234, 21, 11};
  s21::Array<int, 3> copy_array3{234, 21, 11};
  std::array<int, 3> orig_array4(orig_array3);
  s21::Array<int, 3> copy_array4(copy_array3);
  for (int i{}; i < 3; i++) {
    ASSERT_EQ(orig_array3.at(i), copy_array3.at(i));
    ASSERT_EQ(orig_array4.at(i), copy_array4.at(i));
  }
  ASSERT_EQ(orig_array3.size(), copy_array3.size());
  ASSERT_EQ(orig_array3.max_size(), copy_array3.max_size());
  ASSERT_EQ(orig_array4.size(), copy_array4.size());
  ASSERT_EQ(orig_array4.max_size(), copy_array4.max_size());
  std::array<char, 0> orig_ar5;
  s21::Array<char, 0> copy_ar5;
  std::array<char, 0> orig_ar6(orig_ar5);
  s21::Array<char, 0> copy_ar6(copy_ar5);
  ASSERT_EQ(orig_ar5.empty(), copy_ar5.empty());
  ASSERT_EQ(orig_ar6.empty(), copy_ar6.empty());
}

TEST(Array, move_constructor_test) {
  std::array<int, 5> orig_array1{234, 21, 11, 34, 999};
  s21::Array<int, 5> copy_array1{234, 21, 11, 34, 999};
  std::array<int, 5> orig_array2(std::move(orig_array1));
  s21::Array<int, 5> copy_array2(std::move(copy_array1));
  for (size_t i{}; i < copy_array2.size(); i++) {
    ASSERT_EQ(orig_array2.at(i), copy_array2.at(i));
  }
  ASSERT_EQ(orig_array1.size(), copy_array1.size());
  ASSERT_EQ(orig_array1.max_size(), copy_array1.max_size());
  ASSERT_EQ(orig_array2.size(), copy_array2.size());
  ASSERT_EQ(orig_array2.max_size(), copy_array2.max_size());
  std::array<char, 0> orig_ar1;
  s21::Array<char, 0> copy_ar1;
  ASSERT_EQ(orig_ar1.empty(), copy_ar1.empty());
}

TEST(Array, move_operator_test) {
  std::array<int, 5> orig_array1{234, 21, 11, 34, 999};
  s21::Array<int, 5> copy_array1{234, 21, 11, 34, 999};
  std::array<int, 5> orig_array2{25};
  s21::Array<int, 5> copy_array2{25};
  orig_array2 = std::move(orig_array1);
  copy_array2 = std::move(copy_array1);
  for (size_t i{}; i < copy_array2.size(); i++) {
    ASSERT_EQ(orig_array2.at(i), copy_array2.at(i));
  }
  ASSERT_EQ(orig_array1.size(), copy_array1.size());
  ASSERT_EQ(orig_array1.max_size(), copy_array1.max_size());
  ASSERT_EQ(orig_array2.size(), copy_array2.size());
  ASSERT_EQ(orig_array2.max_size(), copy_array2.max_size());
  std::array<char, 0> orig_ar1;
  s21::Array<char, 0> copy_ar1;
  ASSERT_EQ(orig_ar1.empty(), copy_ar1.empty());
}

TEST(Array, iterator_test) {
  std::array<int, 5> orig_array1{234, 21, 11, 34, 999};
  s21::Array<int, 5> copy_array1{234, 21, 11, 34, 999};
  int *orig_beg = orig_array1.begin();
  int *copy_beg = copy_array1.begin();
  int *orig_end = orig_array1.end();
  int *copy_end = copy_array1.end();
  while (orig_beg < orig_end && copy_beg < copy_end) {
    ASSERT_EQ(*orig_beg++, *copy_beg++);
  }
  ASSERT_EQ(orig_array1.size(), copy_array1.size());
  ASSERT_EQ(orig_array1.max_size(), copy_array1.max_size());
  s21::Array<char, 0> copy_ar1;
  ASSERT_TRUE(copy_ar1.begin() == copy_ar1.end());
  s21::Array<double, 3> my_arr{2.3, 4.5555, 6.1234};
  double *d = my_arr.data();
  ASSERT_DOUBLE_EQ(my_arr[0], *d);
}

TEST(Array, fill_test) {
  std::array<size_t, 10> orig_array;
  s21::Array<size_t, 10> my_arr;
  orig_array.fill(555);
  my_arr.fill(555);
  for (size_t i = 0; i < orig_array.size(); i++)
    ASSERT_EQ(orig_array[i], my_arr[i]);
  ASSERT_EQ(orig_array.size(), my_arr.size());
  ;
}

// TEST(ArrayTest, DefaultConstructor) {
//   s21::Array<int, 5> array;
//   EXPECT_EQ(array.size(), 5);
// }

// TEST(ArrayTest, InitializerListConstructor) {
//   s21::Array<int, 4> array_1 = {1, 2, 3, 4};
//   EXPECT_EQ(array_1[0], 1);
//   EXPECT_EQ(array_1[1], 2);
//   EXPECT_EQ(array_1[2], 3);
//   EXPECT_EQ(array_1[3], 4);

//   s21::Array<int, 3> array_2 = {1, 2};
//   EXPECT_EQ(array_2[0], 1);
//   EXPECT_EQ(array_2[1], 2);
//   EXPECT_EQ(array_2[2], 0);
// }

// TEST(ArrayTest, CopyConstructor) {
//   s21::Array<int, 4> array_1 = {1, 2, 3, 4};
//   s21::Array<int, 4> array_2(array_1);

//   EXPECT_EQ(array_2.size(), 4);
//   EXPECT_EQ(array_2[0], 1);
//   EXPECT_EQ(array_2[1], 2);
//   EXPECT_EQ(array_2[2], 3);
//   EXPECT_EQ(array_2[3], 4);
// }

// TEST(ArrayTest, MoveConstructor) {
//   s21::Array<int, 4> array_1 = {1, 2, 3, 4};
//   s21::Array<int, 4> array_2(std::move(array_1));

//   EXPECT_EQ(array_2.size(), 4);
//   EXPECT_EQ(array_2[0], 1);
//   EXPECT_EQ(array_2[1], 2);
//   EXPECT_EQ(array_2[2], 3);
//   EXPECT_EQ(array_2[3], 4);

//   EXPECT_EQ(array_1.size(), 0);
// }

// TEST(ArrayTest, AssignmentOperatorMoving) {
//   s21::Array<int, 4> array_1 = {1, 2, 3, 4};
//   s21::Array<int, 4> array_2 = std::move(array_1);

//   EXPECT_EQ(array_2.size(), 4);
//   EXPECT_EQ(array_2[0], 1);
//   EXPECT_EQ(array_2[1], 2);
//   EXPECT_EQ(array_2[2], 3);
//   EXPECT_EQ(array_2[3], 4);

//   EXPECT_EQ(array_1.size(), 0);
// }

// TEST(ArrayTest, At) {
//   s21::Array<int, 4> array = {1, 2, 3, 4};
//   array.at(0) = 4;
//   EXPECT_EQ(array[0], 4);
// }

// TEST(ArrayTest, AtThrow) {
//   s21::Array<int, 4> array = {1, 2, 3, 4};

//   EXPECT_THROW(array.at(-1) = 4, std::out_of_range);
// }

// TEST(ArrayTest, Operator) {
//   s21::Array<int, 4> array = {1, 2, 3, 4};
//   array[0] = 32344;
//   EXPECT_EQ(array.at(0), 32344);
// }

// TEST(ArrayTest, Front) {
//   s21::Array<int, 4> array = {1, 2, 3, 4};
//   EXPECT_EQ(array.front(), 1);
// }

// TEST(ArrayTest, Back) {
//   s21::Array<int, 4> array = {1, 2, 3, 4};
//   EXPECT_EQ(array.back(), 4);
// }

// TEST(ArrayTest, Data) {
//   s21::Array<int, 4> array = {1, 2, 3, 4};
//   EXPECT_EQ(*array.data(), 1);
// }

// TEST(ArrayTest, Begin) {
//   s21::Array<int, 4> array = {1, 2, 3, 4};
//   EXPECT_EQ(*array.begin(), 1);
// }

// TEST(ArrayTest, End) {
//   s21::Array<int, 4> array = {1, 2, 3, 4};
//   EXPECT_EQ(array.end(), array.begin() + 4);
// }

// TEST(ArrayTest, NotEmpty) {
//   s21::Array<int, 4> array = {1, 2, 3, 4};
//   EXPECT_EQ(array.empty(), false);
// }

// TEST(ArrayTest, Empty) {
//   s21::Array<int, 0> array;
//   EXPECT_EQ(array.empty(), true);
// }

// TEST(ArrayTest, Size) {
//   s21::Array<int, 4> array_1 = {1, 2, 3, 4};
//   EXPECT_EQ(array_1.size(), 4);

//   s21::Array<int, 0> array_2;
//   EXPECT_EQ(array_2.size(), 0);
// }

// TEST(ArrayTest, MaxSize) {
//   s21::Array<int, 4> array_1 = {1, 2, 3, 4};
//   EXPECT_EQ(array_1.max_size(), 4);

//   s21::Array<int, 0> array_2;
//   EXPECT_EQ(array_2.max_size(), 0);
// }

// TEST(ArrayTest, Swap) {
//   s21::Array<int, 4> array_1 = {1, 2, 3, 4};
//   s21::Array<int, 4> array_2 = {11, 12, 13, 14};
//   array_1.swap(array_2);

//   EXPECT_EQ(array_1[0], 11);
//   EXPECT_EQ(array_1[1], 12);
//   EXPECT_EQ(array_1[2], 13);
//   EXPECT_EQ(array_1[3], 14);

//   EXPECT_EQ(array_2[0], 1);
//   EXPECT_EQ(array_2[1], 2);
//   EXPECT_EQ(array_2[2], 3);
//   EXPECT_EQ(array_2[3], 4);
// }

// TEST(ArrayTest, Fill) {
//   s21::Array<int, 4> array = {1, 2, 3, 4};
//   array.fill(21);

//   EXPECT_EQ(array[0], 21);
//   EXPECT_EQ(array[1], 21);
//   EXPECT_EQ(array[2], 21);
//   EXPECT_EQ(array[3], 21);
// }