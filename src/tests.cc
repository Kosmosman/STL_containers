#include <gtest/gtest.h>

#include <array>
#include <map>
#include <set>
#include <string>

#include "s21_avl_tree.h"
#include "s21_map.h"
#include "s21_set.h"

class setTest {
 public:
  s21::set<int> empty_set;
  s21::set<int> set_int{3, 5, 7, 2, 1, 1, 4, 6};
  s21::set<std::string> set_string{"baka", "obon", "kokoro"};
  s21::set<double> set_double{1.2, 2.0, 3.345, -1.233};

  std::set<int> empty_set_orig;
  std::set<int> set_int_orig{3, 5, 7, 2, 1, 1, 4, 6};
  std::set<std::string> set_string_orig{"baka", "obon", "kokoro"};
  std::set<double> set_double_orig{1.2, 2.0, 3.345, -1.233};
};

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

TEST(Tree, Erasetest) {
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

TEST(set, Constructor) {
  setTest tmp;
  EXPECT_EQ(*(tmp.empty_set.begin()) == 0, true);
}

TEST(set, ConstructorList) {
  setTest tmp;
  int eq[7]{1, 2, 3, 4, 5, 6, 7};
  int* pos = eq;
  for (auto it : tmp.set_int) {
    EXPECT_EQ(it == *(pos++), true);
  }
}

TEST(set, ConstructorCopy) {
  setTest tmp;
  s21::set<double> two{tmp.set_double};
  double eq[4]{-1.233, 1.2, 2.0, 3.345};
  double* pos = eq;
  for (auto it : two) {
    EXPECT_EQ(it == *(pos++), true);
  }
  tmp.set_double.Clear();
  EXPECT_TRUE(tmp.set_double.Empty());
  EXPECT_TRUE(!two.Empty());
}

TEST(set, ConstructorMove) {
  setTest tmp;
  s21::set<double> two{std::move(tmp.set_double)};
  double eq[4]{-1.233, 1.2, 2.0, 3.345};
  double* pos = eq;
  for (auto it : two) {
    EXPECT_EQ(it == *(pos++), true);
  }
  EXPECT_TRUE(tmp.set_double.Empty());
  EXPECT_TRUE(!two.Empty());
}

TEST(set, OperatorsPlusTest) {
  setTest tmp;
  s21::set<int>::iterator it(tmp.set_int.begin());
  EXPECT_TRUE(*(it++) == 1);
  EXPECT_TRUE(*(it) == 2);
  EXPECT_TRUE(*(++it) == 3);
}

TEST(set, OperatorsMinusTest) {
  setTest tmp;
  s21::set<int>::iterator it(tmp.set_int.Find(7));
  EXPECT_TRUE(*(it--) == 7);
  EXPECT_TRUE(*(it) == 6);
  EXPECT_TRUE(*(--it) == 5);
}

TEST(set, ContainsTest) {
  setTest tmp;
  s21::set<int>::iterator it(tmp.set_int.Find(7));
  *(it) = 8;
  EXPECT_TRUE(tmp.set_int.Contains(8));
}

TEST(set, FindTest) {
  setTest tmp;
  EXPECT_TRUE(tmp.set_int.Find(1) == tmp.set_int.begin());
}

TEST(set, SizeTest) {
  setTest tmp;
  EXPECT_TRUE(tmp.set_int.Find(1) == tmp.set_int.begin());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
