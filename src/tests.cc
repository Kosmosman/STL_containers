#include <gtest/gtest.h>

#include <set>
#include <string>

#include "s21_avl_tree.h"

TEST(Containers, CreateTreeInt) {
  s21::AvlTree<int, int> one;
  one.Insert(1, 1);
  one.Insert(10, 10);
  one.Insert(2, 2);
  one.Insert(5, 5);
  one.Insert(1, 1);
  std::set<int> two{1, 10, 2, 5, 1};
  EXPECT_EQ(one.GetSize(), two.size());
}

TEST(Containers, CreateTreeIntInitList) {
  s21::AvlTree<int, int> one{1, 10, 2, 5, 1};
  std::set<int> two{1, 10, 2, 5, 1};
  EXPECT_EQ(one.GetSize(), two.size());
}

TEST(Containers, CreateTreeCopy) {
  s21::AvlTree<int, int> one{1, 2, 3};
  s21::AvlTree<int, int> two(one);
  EXPECT_EQ(one.GetSize() == two.GetSize(), true);
}

TEST(Containers, CreateTreeMove) {
  s21::AvlTree<int, int> one{1, 2, 3};
  s21::AvlTree<int, int> two(std::move(one));
  EXPECT_EQ(one.GetSize() == 0, true);
  EXPECT_EQ(two.GetSize() == 3, true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}