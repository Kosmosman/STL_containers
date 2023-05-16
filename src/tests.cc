#include <gtest/gtest.h>

#include <set>
#include <string>

#include "s21_avl_tree.h"
#include "s21_set.h"

TEST(Tree, CreateTreeInt) {
  s21::AvlTree<int, int> one;
  EXPECT_TRUE(one.Empty());
}

TEST(Tree, CreateTreeIntInitList) {
  s21::AvlTree<int, int> one{1, 10, 2, 5, 1};
  std::set<int> two{1, 10, 2, 5, 1};
  EXPECT_EQ(one.GetSize(), two.size());
}

TEST(Tree, CreateTreeCopy) {
  s21::AvlTree<int, int> one{1, 2, 3};
  s21::AvlTree<int, int> two(one);
  EXPECT_EQ(one.GetSize() == two.GetSize(), true);
}

TEST(Tree, CreateTreeMove) {
  s21::AvlTree<int, int> one{1, 2, 3};
  EXPECT_EQ(one.GetSize() == 3, true);
  s21::AvlTree<int, int> two(std::move(one));
  EXPECT_EQ(one.GetSize() == 0, true);
  EXPECT_EQ(two.GetSize() == 3, true);
}

TEST(Tree, InsertTest) {
  s21::AvlTree<int, int> one;
  one.Insert(5, 5);
  one.Insert(1, 1);
  one.Insert(10, 10);
  int eq[3]{1, 5, 10};
  for (auto it : eq) {
    EXPECT_TRUE(one.Find(it));
  }
  EXPECT_FALSE(one.Find(2));
}

TEST(Tree, EraseTest) {
  s21::AvlTree<int, int> one{1, 2, 3};
  EXPECT_TRUE(one.Find(1));
  one.Erase(one.Find(1));
  EXPECT_FALSE(one.Find(1));
}

TEST(Tree, EmptyTest) {
  s21::AvlTree<int, int> one{6, 4, 3};
  s21::AvlTree<int, int> two;
  EXPECT_TRUE(!one.Empty());
  EXPECT_TRUE(two.Empty());
}

TEST(Tree, ClearTest) {
  s21::AvlTree<int, int> one{25, 44, 9};
  EXPECT_TRUE(one.GetSize() == 3);
  one.Clear();
  EXPECT_TRUE(one.Empty());
}

TEST(Set, Constructor) {
  s21::Set<int> one;
  EXPECT_EQ(*(one.begin()) == 0, true);
}

TEST(Set, ConstructorList) {
  s21::Set<int> one{5, 19, 2, 5, 29, 33};
  int eq[5]{2, 5, 19, 29, 33};
  int* pos = eq;
  for (auto it : one) {
    EXPECT_EQ(it == *(pos++), true);
  }
}

TEST(Set, ConstructorCopy) {
  s21::Set<int> one{10, 20, 40, 30, 2};
  s21::Set<int> two{one};
  int eq[5]{2, 10, 20, 30, 40};
  int* pos = eq;
  for (auto it : two) {
    EXPECT_EQ(it == *(pos++), true);
  }
  one.Clear();
  EXPECT_TRUE(one.Empty());
  EXPECT_TRUE(!two.Empty());
}

TEST(Set, ConstructorMove) {
  s21::Set<int> one{10, 20, 40, 30, 2};
  s21::Set<int> two{std::move(one)};
  int eq[5]{2, 10, 20, 30, 40};
  int* pos = eq;
  for (auto it : two) {
    EXPECT_EQ(it == *(pos++), true);
  }
  EXPECT_TRUE(one.Empty());
  EXPECT_TRUE(!two.Empty());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}