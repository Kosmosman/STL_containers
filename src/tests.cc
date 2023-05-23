#include <gtest/gtest.h>

#include <array>
#include <map>
#include <set>
#include <string>

#include "s21_avl_tree.h"
#include "s21_map.h"
#include "s21_set.h"

class SetTest {
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
  one.Insert(5);
  one.Insert(1);
  one.Insert(10);
  int eq[3]{1, 5, 10};
  for (auto it : eq) {
    EXPECT_TRUE(one.Find(it));
  }
  EXPECT_FALSE(one.Find(2) != one.End());
}

TEST(Tree, EraseTest) {
  s21::AvlTree<int, int> one{1, 2, 3};
  EXPECT_TRUE(one.Find(1));
  one.Erase(one.Find(1));
  EXPECT_FALSE(one.Find(1) != one.End());
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
  SetTest tmp;
  EXPECT_EQ(*(tmp.empty_set.begin()) == 0, true);
}

TEST(set, ConstructorList) {
  SetTest tmp;
  int eq[7]{1, 2, 3, 4, 5, 6, 7};
  int* pos = eq;
  for (auto it : tmp.set_int) {
    EXPECT_EQ(it == *(pos++), true);
  }
}

TEST(set, ConstructorCopy) {
  SetTest tmp;
  s21::set<double> two{tmp.set_double};
  double eq[4]{-1.233, 1.2, 2.0, 3.345};
  double* pos = eq;
  for (auto it : two) {
    EXPECT_EQ(it == *(pos++), true);
  }
  tmp.set_double.clear();
  EXPECT_TRUE(tmp.set_double.empty());
  EXPECT_TRUE(!two.empty());
}

TEST(set, ConstructorMove) {
  SetTest tmp;
  s21::set<double> two{std::move(tmp.set_double)};
  double eq[4]{-1.233, 1.2, 2.0, 3.345};
  double* pos = eq;
  for (auto it : two) {
    EXPECT_EQ(it == *(pos++), true);
  }
  EXPECT_TRUE(tmp.set_double.empty());
  EXPECT_TRUE(!two.empty());
}

TEST(set, OperatorsPlusTest) {
  SetTest tmp;
  s21::set<int>::iterator it(tmp.set_int.begin());
  EXPECT_TRUE(*(it++) == 1);
  EXPECT_TRUE(*(it) == 2);
  EXPECT_TRUE(*(++it) == 3);
}

TEST(set, OperatorsMinusTest) {
  SetTest tmp;
  s21::set<int>::iterator it(tmp.set_int.find(7));
  EXPECT_TRUE(*(it--) == 7);
  EXPECT_TRUE(*(it) == 6);
  EXPECT_TRUE(*(--it) == 5);
}

TEST(set, FindTest) {
  SetTest tmp;
  EXPECT_TRUE(tmp.set_int.find(1) == tmp.set_int.begin());
}

TEST(set, SizeTest) {
  SetTest tmp;
  EXPECT_TRUE(tmp.set_int.find(1) == tmp.set_int.begin());
}

class TestSet {
 public:
  s21::set<int> s21_set_empty;
  s21::set<int> s21_set_ten{1, 2, 56, 76, 123, 53, 78, 43, 21, 100};
  s21::set<int> s21_set_copy;
  std::set<int> std_set_copy;
  s21::set<int> s21_move;
  std::set<int> std_move;
  s21::set<int> s21_set_swap{95, 94, 93, 92};
  std::set<int> std_set_swap{95, 94, 93, 92};
  s21::set<int> s21_set_merge{1, 2, 3, 4, 5};
  std::set<int> std_set_merge{1, 2, 3, 4, 5};

  std::set<int> std_set_empty;
  std::set<int> std_set_ten{1, 2, 56, 76, 123, 53, 78, 43, 21, 100};
};

TEST(Set, constructor_default) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_empty.size(), tester.std_set_empty.size());
  EXPECT_EQ(tester.s21_set_empty.empty(), tester.std_set_empty.empty());
}

TEST(Set, constructor_initialazer) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.s21_set_ten.find(1) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(1) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(2) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(2) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(3) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(3) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(4) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(4) != tester.std_set_ten.end());
}

TEST(Set, constructor_copy) {
  TestSet tester;
  s21::set<int> s21_empty(tester.s21_set_ten);
  std::set<int> std_empty(tester.std_set_ten);
  EXPECT_EQ(s21_empty.find(1) != s21_empty.end(),
            std_empty.find(1) != std_empty.end());
  EXPECT_EQ(s21_empty.find(2) != s21_empty.end(),
            std_empty.find(2) != std_empty.end());
  EXPECT_EQ(s21_empty.find(3) != s21_empty.end(),
            std_empty.find(3) != std_empty.end());
  EXPECT_EQ(s21_empty.find(4) != s21_empty.end(),
            std_empty.find(4) != std_empty.end());
  EXPECT_EQ(s21_empty.size(), std_empty.size());
  EXPECT_EQ(s21_empty.empty(), std_empty.empty());
}

TEST(Set, construct_move) {
  TestSet tester;
  s21::set<int> s21_move = std::move(tester.s21_set_ten);
  std::set<int> std_move = std::move(tester.std_set_ten);
  EXPECT_EQ(s21_move.find(1) != s21_move.end(),
            std_move.find(1) != std_move.end());
  EXPECT_EQ(s21_move.find(2) != s21_move.end(),
            std_move.find(2) != std_move.end());
  EXPECT_EQ(s21_move.find(3) != s21_move.end(),
            std_move.find(3) != std_move.end());
  EXPECT_EQ(s21_move.find(4) != s21_move.end(),
            std_move.find(4) != std_move.end());
  EXPECT_EQ(s21_move.size(), std_move.size());
  EXPECT_EQ(s21_move.empty(), std_move.empty());
}

TEST(Set, operator_move) {
  TestSet tester;
  tester.s21_move = std::move(tester.s21_set_ten);
  tester.std_move = std::move(tester.std_set_ten);
  EXPECT_EQ(tester.s21_move.find(1) != tester.s21_move.end(),
            tester.std_move.find(1) != tester.std_move.end());
  EXPECT_EQ(tester.s21_move.find(2) != tester.s21_move.end(),
            tester.std_move.find(2) != tester.std_move.end());
  EXPECT_EQ(tester.s21_move.find(3) != tester.s21_move.end(),
            tester.std_move.find(3) != tester.std_move.end());
  EXPECT_EQ(tester.s21_move.find(4) != tester.s21_move.end(),
            tester.std_move.find(4) != tester.std_move.end());
  EXPECT_EQ(tester.s21_move.size(), tester.std_move.size());
  EXPECT_EQ(tester.s21_move.empty(), tester.std_move.empty());
}

TEST(Set, operator_copy) {
  TestSet tester;
  tester.s21_set_copy = tester.s21_set_ten;
  tester.std_set_copy = tester.std_set_ten;
  EXPECT_EQ(tester.s21_set_copy.find(1) != tester.s21_set_copy.end(),
            tester.std_set_copy.find(1) != tester.std_set_copy.end());
  EXPECT_EQ(tester.s21_set_copy.find(2) != tester.s21_set_copy.end(),
            tester.std_set_copy.find(2) != tester.std_set_copy.end());
  EXPECT_EQ(tester.s21_set_copy.find(3) != tester.s21_set_copy.end(),
            tester.std_set_copy.find(3) != tester.std_set_copy.end());
  EXPECT_EQ(tester.s21_set_copy.find(4) != tester.s21_set_copy.end(),
            tester.std_set_copy.find(4) != tester.std_set_copy.end());
  EXPECT_EQ(tester.s21_set_copy.size(), tester.std_set_copy.size());
  EXPECT_EQ(tester.s21_set_copy.empty(), tester.std_set_copy.empty());
}

TEST(Set, function_not_empty) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.s21_set_ten.empty(), tester.std_set_ten.empty());
}

TEST(Set, function_empty) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_empty.size(), tester.std_set_empty.size());
  EXPECT_EQ(tester.s21_set_empty.empty(), tester.std_set_empty.empty());
}

TEST(Set, function_size_empty) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_empty.size(), tester.std_set_empty.size());
}

TEST(Set, function_size_not_empty) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
}

TEST(Set, function_max_sez_empty) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_empty.max_size(), tester.std_set_empty.max_size());
}

TEST(Set, function_max_siez_not_empty) {
  TestSet tester;
  EXPECT_EQ(tester.s21_set_ten.max_size(), tester.std_set_ten.max_size());
}

TEST(Set, function_max_size_float_empty) {
  s21::set<float> s21_float_empty;
  std::set<float> std_float_empty;
  EXPECT_EQ(s21_float_empty.max_size(), std_float_empty.max_size());
}

TEST(Set, function_swap_not_empty) {
  TestSet tester;
  tester.s21_set_swap.swap(tester.s21_set_ten);
  tester.std_set_swap.swap(tester.std_set_ten);
  EXPECT_EQ(tester.s21_set_swap.find(1) != tester.s21_set_swap.end(),
            tester.std_set_swap.find(1) != tester.std_set_swap.end());
  EXPECT_EQ(tester.s21_set_swap.find(56) != tester.s21_set_swap.end(),
            tester.std_set_swap.find(56) != tester.std_set_swap.end());
  EXPECT_EQ(tester.s21_set_swap.find(76) != tester.s21_set_swap.end(),
            tester.std_set_swap.find(76) != tester.std_set_swap.end());
  EXPECT_EQ(tester.s21_set_ten.find(95) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(95) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(94) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(94) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(93) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(93) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_swap.size(), tester.std_set_swap.size());
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
}

TEST(Set, function_swap_empty) {
  TestSet tester;
  tester.s21_set_empty.swap(tester.s21_set_swap);
  tester.std_set_empty.swap(tester.std_set_swap);

  EXPECT_EQ(tester.s21_set_empty.find(95) != tester.s21_set_empty.end(),
            tester.std_set_empty.find(95) != tester.std_set_empty.end());
  EXPECT_EQ(tester.s21_set_empty.find(94) != tester.s21_set_empty.end(),
            tester.std_set_empty.find(94) != tester.std_set_empty.end());
  EXPECT_EQ(tester.s21_set_empty.find(93) != tester.s21_set_empty.end(),
            tester.std_set_empty.find(93) != tester.std_set_empty.end());

  EXPECT_EQ(tester.s21_set_empty.size(), tester.std_set_empty.size());
  EXPECT_EQ(tester.s21_set_empty.empty(), tester.std_set_empty.empty());
  EXPECT_EQ(tester.s21_set_swap.size(), tester.std_set_swap.size());
  EXPECT_EQ(tester.s21_set_swap.empty(), tester.std_set_swap.empty());
}
TEST(Set, function_merge_with_duplicates) {
  TestSet tester;
  tester.s21_set_merge.merge(tester.s21_set_ten);
  tester.std_set_merge.merge(tester.std_set_ten);

  EXPECT_EQ(tester.s21_set_merge.find(1) != tester.s21_set_merge.end(),
            tester.std_set_merge.find(1) != tester.std_set_merge.end());
  EXPECT_EQ(tester.s21_set_merge.find(2) != tester.s21_set_merge.end(),
            tester.std_set_merge.find(2) != tester.std_set_merge.end());
  EXPECT_EQ(tester.s21_set_merge.find(76) != tester.s21_set_merge.end(),
            tester.std_set_merge.find(76) != tester.std_set_merge.end());

  EXPECT_EQ(tester.s21_set_merge.size(), tester.std_set_merge.size());
  EXPECT_EQ(tester.std_set_merge.empty(), tester.std_set_merge.empty());
}

TEST(Set, function_merge_wihout_duplicates) {
  TestSet tester;
  tester.s21_set_ten.merge(tester.s21_set_swap);
  tester.std_set_ten.merge(tester.std_set_swap);

  EXPECT_EQ(tester.s21_set_ten.find(95) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(95) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(1) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(1) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(94) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(94) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(76) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(76) != tester.std_set_ten.end());

  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.std_set_ten.empty(), tester.std_set_ten.empty());
  EXPECT_EQ(tester.s21_set_swap.size(), tester.std_set_swap.size());
  EXPECT_EQ(tester.s21_set_swap.empty(), tester.std_set_swap.empty());
}

TEST(Set, function_clear_not_empty) {
  TestSet tester;
  tester.s21_set_ten.clear();
  tester.std_set_ten.clear();
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.s21_set_ten.empty(), tester.std_set_ten.empty());
}

TEST(Set, function_clear_empty) {
  TestSet tester;
  tester.s21_set_empty.clear();
  tester.std_set_empty.clear();
  EXPECT_EQ(tester.s21_set_empty.size(), tester.std_set_empty.size());
  EXPECT_EQ(tester.std_set_empty.empty(), tester.std_set_empty.empty());
}

TEST(Set, function_begin_not_empty) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_ten.begin();
  std::set<int>::iterator j = tester.std_set_ten.begin();
  EXPECT_EQ(*i, *j);
}

TEST(Set, function_begin_empty) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_empty.begin();
  std::set<int>::iterator j = tester.std_set_empty.begin();
  EXPECT_EQ(*i, *j);
}
TEST(Set, function_const_begin_not_empty) {
  TestSet tester;
  s21::set<int>::const_iterator i = tester.s21_set_ten.begin();
  std::set<int>::const_iterator j = tester.std_set_ten.begin();
  EXPECT_EQ(*i, *j);
}

TEST(Set, function_const_begin_empty) {
  TestSet tester;
  s21::set<int>::const_iterator i = tester.s21_set_empty.begin();
  std::set<int>::const_iterator j = tester.std_set_empty.begin();
  EXPECT_EQ(*i, *j);
}

TEST(Set, function_end_not_empty) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_ten.end();
  std::set<int>::iterator j = tester.std_set_ten.end();
  --i;
  --j;
  EXPECT_EQ(*i, *j);
}

TEST(Set, function_end_empty) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_empty.end();
  std::set<int>::iterator j = tester.std_set_empty.end();
  EXPECT_EQ(*i, *j);
}
TEST(Set, function_const_end_not_empty) {
  TestSet tester;
  s21::set<int>::const_iterator i = tester.s21_set_ten.end();
  std::set<int>::const_iterator j = tester.std_set_ten.end();
  --i;
  --j;
  EXPECT_EQ(*i, *j);
}

TEST(Set, function_const_end_empty) {
  TestSet tester;
  s21::set<int>::const_iterator i = tester.s21_set_empty.end();
  std::set<int>::const_iterator j = tester.std_set_empty.end();
  EXPECT_EQ(*i, *j);
}
TEST(Set, operator_plus) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_ten.begin();
  std::set<int>::iterator j = tester.std_set_ten.begin();
  while (i != tester.s21_set_ten.end() && j != tester.std_set_ten.end()) {
    EXPECT_EQ(*i, *j);
    ++i;
    ++j;
  }
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.std_set_ten.empty(), tester.std_set_ten.empty());
}

TEST(Set, operator_minus) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_ten.end();
  std::set<int>::iterator j = tester.std_set_ten.end();
  while (i != tester.s21_set_ten.begin() && j != tester.std_set_ten.begin()) {
    --i;
    --j;
    EXPECT_EQ(*i, *j);
  }
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.s21_set_ten.empty(), tester.std_set_ten.empty());
}

TEST(Set, operation_assignment) {
  TestSet tester;
  s21::set<int>::iterator iter_1 = tester.s21_set_ten.begin();
  s21::set<int>::iterator iter_3 = iter_1;
  std::set<int>::iterator iter_2 = tester.std_set_ten.begin();
  std::set<int>::iterator iter_4 = iter_2;
  ASSERT_EQ(*iter_1, *iter_3);
  ASSERT_EQ(*iter_2, *iter_4);
}
TEST(Set, operation_equal) {
  TestSet tester;
  s21::set<int>::iterator it1 = tester.s21_set_ten.begin();
  s21::set<int>::iterator it3 = tester.s21_set_ten.begin();
  std::set<int>::iterator it2 = tester.std_set_ten.begin();
  std::set<int>::iterator it4 = tester.std_set_ten.begin();
  ASSERT_EQ(it1 == it3, it2 == it4);
}
TEST(Set, operation_not_equal) {
  TestSet tester;
  s21::set<int>::iterator iter_1 = tester.s21_set_ten.begin();
  std::set<int>::iterator iter_2 = tester.std_set_ten.begin();
  ASSERT_EQ(iter_1 != tester.s21_set_ten.end(),
            iter_2 != tester.std_set_ten.end());
}

TEST(Set, function_insert) {
  TestSet tester;
  std::pair<s21::set<int>::iterator, bool> iter_1 =
      tester.s21_set_ten.insert(45);
  std::pair<std::set<int>::iterator, bool> iter_2 =
      tester.std_set_ten.insert(45);
  EXPECT_EQ(*(iter_1.first), *(iter_2.first));
  EXPECT_EQ(iter_1.second, iter_2.second);
}

TEST(Set, function_find_have) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_ten.find(1);
  std::set<int>::iterator j = tester.std_set_ten.find(1);
  EXPECT_EQ(i != tester.s21_set_ten.end(), j != tester.std_set_ten.end());
}

TEST(Set, function_find_dont_have) {
  TestSet tester;
  s21::set<int>::iterator i = tester.s21_set_ten.find(100);
  std::set<int>::iterator j = tester.std_set_ten.find(100);
  EXPECT_EQ(i == tester.s21_set_ten.end(), j == tester.std_set_ten.end());
}

TEST(Set, function_erase) {
  TestSet tester;
  tester.s21_set_ten.erase(tester.s21_set_ten.begin());
  tester.std_set_ten.erase(tester.std_set_ten.begin());
  s21::set<int>::iterator iter_1 = tester.s21_set_ten.find(1);
  std::set<int>::iterator iter_2 = tester.std_set_ten.find(1);
  ASSERT_EQ(iter_1 == tester.s21_set_ten.end(),
            iter_2 == tester.std_set_ten.end());
}
TEST(Set, functions_erase_alot) {
  TestSet tester;
  s21::set<int>::iterator it1 = tester.s21_set_ten.find(76);
  std::set<int>::iterator it2 = tester.std_set_ten.find(76);
  tester.s21_set_ten.erase(it1);
  tester.std_set_ten.erase(it2);
  it1 = tester.s21_set_ten.find(123);
  it2 = tester.std_set_ten.find(123);
  tester.s21_set_ten.erase(it1);
  tester.std_set_ten.erase(it2);
  it1 = tester.s21_set_ten.find(43);
  it2 = tester.std_set_ten.find(43);
  tester.s21_set_ten.erase(it1);
  tester.std_set_ten.erase(it2);
  ASSERT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
}

/* --------------- MAP ------------------- */

class TestMap {
 public:
  s21::map<int, int> s21_map_empty;
  s21::map<int, int> s21_map_four{{1, 1}, {2, 2}, {3, 3}, {4, 4}};
  s21::map<int, int> s21_map_swap{{1, 95}, {2, 94}, {3, 93}};

  std::map<int, int> std_map_empty;
  std::map<int, int> std_map_four{{
                                      1,
                                      1,
                                  },
                                  {2, 2},
                                  {3, 3},
                                  {4, 4}};
  std::map<int, int> std_map_swap{{1, 95}, {2, 95}, {3, 95}};
};

TEST(Map, construcor_default) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
}

TEST(Map, construcot_initializer) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_four[1], tester.std_map_four[1]);
  EXPECT_EQ(tester.s21_map_four[4], tester.std_map_four[4]);
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.std_map_four.empty(), tester.std_map_four.empty());
}

TEST(Map, constructor_copy_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_copy(tester.s21_map_empty);
  std::map<int, int> std_map_copy(tester.std_map_empty);
  EXPECT_EQ(s21_map_copy.size(), std_map_copy.size());
  EXPECT_EQ(std_map_copy.empty(), std_map_copy.empty());
}

TEST(Map, constructor_copy_not_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_copy(tester.s21_map_four);
  std::map<int, int> std_map_copy(tester.std_map_four);
  EXPECT_EQ(s21_map_copy[1], std_map_copy[1]);
  EXPECT_EQ(s21_map_copy[4], std_map_copy[4]);
  EXPECT_EQ(s21_map_copy.size(), std_map_copy.size());
  EXPECT_EQ(std_map_copy.empty(), std_map_copy.empty());
}

TEST(Map, constructor_move_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_move = std::move(tester.s21_map_empty);
  std::map<int, int> std_map_move = std::move(tester.std_map_empty);
  EXPECT_EQ(s21_map_move.size(), std_map_move.size());
  EXPECT_EQ(s21_map_move.empty(), std_map_move.empty());
}

TEST(Map, constructor_move_not_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_move = std::move(tester.s21_map_four);
  std::map<int, int> std_map_move = std::move(tester.std_map_four);
  EXPECT_EQ(s21_map_move[1], std_map_move[1]);
  EXPECT_EQ(s21_map_move[4], std_map_move[4]);
  EXPECT_EQ(s21_map_move.size(), std_map_move.size());
  EXPECT_EQ(s21_map_move.empty(), std_map_move.empty());
}

TEST(Map, operator_copy_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_copy;
  std::map<int, int> std_map_copy;
  s21_map_copy = tester.s21_map_four;
  std_map_copy = tester.std_map_four;
  EXPECT_EQ(s21_map_copy[1], std_map_copy[1]);
  EXPECT_EQ(s21_map_copy[4], std_map_copy[4]);
  EXPECT_EQ(s21_map_copy.size(), std_map_copy.size());
  EXPECT_EQ(s21_map_copy.empty(), std_map_copy.empty());
}

TEST(Map, operator_copy_not_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_copy{{1, 1}, {2, 2}};
  std::map<int, int> std_map_copy{{1, 1}, {2, 2}};
  s21_map_copy = tester.s21_map_four;
  std_map_copy = tester.std_map_four;
  EXPECT_EQ(s21_map_copy[1], std_map_copy[1]);
  EXPECT_EQ(s21_map_copy[4], std_map_copy[4]);
  EXPECT_EQ(s21_map_copy.size(), std_map_copy.size());
  EXPECT_EQ(s21_map_copy.empty(), std_map_copy.empty());
}

TEST(Map, operator_move_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_move;
  std::map<int, int> std_map_move;
  s21_map_move = std::move(tester.s21_map_four);
  std_map_move = std::move(tester.std_map_four);
  EXPECT_EQ(s21_map_move[1], std_map_move[1]);
  EXPECT_EQ(std_map_move[4], std_map_move[4]);
  EXPECT_EQ(s21_map_move.size(), std_map_move.size());
  EXPECT_EQ(s21_map_move.empty(), std_map_move.empty());
}

TEST(Map, operator_move_not_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_move{{1, 1}, {2, 2}};
  std::map<int, int> std_map_move{{1, 1}, {2, 2}};
  s21_map_move = std::move(tester.s21_map_empty);
  std_map_move = std::move(tester.std_map_empty);
  EXPECT_EQ(s21_map_move[1], std_map_move[1]);
  EXPECT_EQ(s21_map_move[2], std_map_move[2]);
  EXPECT_EQ(s21_map_move.size(), std_map_move.size());
  EXPECT_EQ(s21_map_move.empty(), std_map_move.empty());
}

TEST(Map, function_empty_empty) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
  EXPECT_EQ(tester.s21_map_empty[1], tester.std_map_empty[1]);
}

TEST(Map, function_empty_not_empty) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ(tester.s21_map_four[1], tester.std_map_four[1]);
}

TEST(Map, function_size_empty) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
  EXPECT_EQ(tester.s21_map_empty[1], tester.std_map_empty[1]);
}

TEST(Map, function_size_not_empty) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.std_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ(tester.s21_map_four[1], tester.std_map_four[1]);
  EXPECT_EQ(tester.s21_map_four[4], tester.std_map_four[4]);
}

TEST(Map, function_max_size_empty) {
  TestMap tester;
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
  EXPECT_EQ(tester.s21_map_empty.max_size(), tester.std_map_empty.max_size());
}

TEST(Map, function_swap_empty) {
  s21::map<int, int> m1({{1, 8}, {4, 2}, {2, 3}});
  s21::map<int, int> m2;
  m1.swap(m2);

  std::map<int, int> m3({{1, 8}, {4, 2}, {2, 3}});
  std::map<int, int> m4;
  m3.swap(m4);

  ASSERT_EQ(m2[1], m4[1]);
  ASSERT_EQ(m2[2], m4[2]);
  ASSERT_EQ(m2[4], m4[4]);

  ASSERT_EQ(m1.size(), m3.size());
  ASSERT_EQ(m2.size(), m4.size());
}

TEST(Map, function_swap_not_empty) {
  TestMap tester;
  s21::map<int, int> s21_map_swap{{1, 1}, {2, 2}};
  std::map<int, int> std_map_swap{{1, 1}, {2, 2}};
  s21_map_swap.swap(tester.s21_map_four);
  std_map_swap.swap(tester.std_map_four);
  EXPECT_EQ(s21_map_swap[1], std_map_swap[1]);
  EXPECT_EQ(s21_map_swap[4], std_map_swap[4]);
  EXPECT_EQ(s21_map_swap.size(), std_map_swap.size());
  EXPECT_EQ(s21_map_swap.empty(), std_map_swap.empty());
}

TEST(Map, WithDuplicatesCase) {
  s21::map<int, int> m1({{1, 8}, {4, 2}, {2, 3}});
  s21::map<int, int> m2({{1, 3}, {2, 2}});
  m1.merge(m2);

  std::map<int, int> m3({{1, 8}, {4, 2}, {2, 3}});
  std::map<int, int> m4({{1, 3}, {2, 2}});
  m3.merge(m4);

  ASSERT_EQ(m1[1], m3[1]);
  ASSERT_EQ(m1[2], m3[2]);
  ASSERT_EQ(m1[4], m3[4]);

  ASSERT_EQ(m2[1], m4[1]);
  ASSERT_EQ(m2[2], m4[2]);

  ASSERT_EQ(m1.size(), m3.size());
  ASSERT_EQ(m2.size(), m4.size());
}
TEST(Map, WithoutDuplicatesCase) {
  s21::map<int, int> m1({{1, 2}, {3, 4}, {4, 5}});
  s21::map<int, int> m2({{5, 6}, {7, 7}});
  m1.merge(m2);

  std::map<int, int> m3({{1, 2}, {3, 4}, {4, 5}});
  std::map<int, int> m4({{5, 6}, {7, 7}});
  m3.merge(m4);

  ASSERT_EQ(m1[1], m3[1]);
  ASSERT_EQ(m1[3], m3[3]);
  ASSERT_EQ(m1[4], m3[4]);
  ASSERT_EQ(m1[5], m3[5]);
  ASSERT_EQ(m1[7], m3[7]);

  ASSERT_EQ(m1.size(), m3.size());
  ASSERT_EQ(m2.size(), m4.size());
}
TEST(Map, function_clear_empty) {
  TestMap tester;
  tester.s21_map_empty.clear();
  tester.std_map_empty.clear();
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
}
TEST(Map, function_clear_not_empty) {
  TestMap tester;
  tester.s21_map_four.clear();
  tester.std_map_four.clear();
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
}
TEST(Map, function_begin_empty) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_empty.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_empty.begin();
  EXPECT_EQ(iter_1 == tester.s21_map_empty.end(),
            iter_2 == tester.std_map_empty.end());
}

TEST(Map, function_begin_not_empty) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ(iter_1 != tester.s21_map_four.end(),
            iter_2 != tester.std_map_four.end());
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}
TEST(Map, const_begin_empty) {
  TestMap tester;
  s21::map<int, int>::const_iterator iter_1 = tester.s21_map_empty.begin();
  std::map<int, int>::const_iterator iter_2 = tester.std_map_empty.begin();
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
  EXPECT_EQ(iter_1 == tester.s21_map_empty.end(),
            iter_2 == tester.std_map_empty.end());
}
TEST(Map, const_begin_not_empty) {
  TestMap tester;
  s21::map<int, int>::const_iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::const_iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ(iter_1 != tester.s21_map_four.end(),
            iter_2 != tester.std_map_four.end());
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}
TEST(Map, operator_plus) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}
TEST(Map, operator_minus) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  --iter_1;
  --iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}

TEST(Map, operator_assignment) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  s21::map<int, int>::iterator iter_3 = iter_1;
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  std::map<int, int>::iterator iter_4 = iter_2;
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ((*iter_1).second, (*iter_3).second);
  EXPECT_EQ((*iter_2).second, (*iter_4).second);
}
TEST(Map, operator_equal) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  s21::map<int, int>::iterator iter_3 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_empty.begin();
  std::map<int, int>::iterator iter_4 = tester.std_map_empty.begin();
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
  EXPECT_EQ(iter_1 == iter_3, iter_2 == iter_4);
}
TEST(Map, operatort_not_equal) {
  TestMap tester;
  s21::map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ(iter_1 != tester.s21_map_four.end(),
            iter_2 != tester.std_map_empty.end());
}
TEST(Map, const_operator_plus) {
  TestMap tester;
  s21::map<int, int>::const_iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::const_iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}
TEST(Map, const_operator_minus) {
  TestMap tester;
  s21::map<int, int>::const_iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::const_iterator iter_2 = tester.std_map_four.begin();
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  --iter_1;
  --iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}

TEST(Map, const_operator_assignment) {
  TestMap tester;
  s21::map<int, int>::const_iterator iter_1 = tester.s21_map_four.begin();
  s21::map<int, int>::const_iterator iter_3 = iter_1;
  std::map<int, int>::const_iterator iter_2 = tester.std_map_four.begin();
  std::map<int, int>::const_iterator iter_4 = iter_2;
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ((*iter_1).second, (*iter_3).second);
  EXPECT_EQ((*iter_2).second, (*iter_4).second);
}
TEST(Map, const_operator_equal) {
  TestMap tester;
  s21::map<int, int>::const_iterator iter_1 = tester.s21_map_four.begin();
  s21::map<int, int>::const_iterator iter_3 = tester.s21_map_four.begin();
  std::map<int, int>::const_iterator iter_2 = tester.std_map_empty.begin();
  std::map<int, int>::const_iterator iter_4 = tester.std_map_empty.begin();
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
  EXPECT_EQ(iter_1 == iter_3, iter_2 == iter_4);
}
TEST(Map, const_operatort_not_equal) {
  TestMap tester;
  s21::map<int, int>::const_iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ(iter_1 != tester.s21_map_four.end(),
            iter_2 != tester.std_map_empty.end());
}

TEST(Map, function_insert_without_duplicate) {
  TestMap tester;
  std::pair<s21::map<int, int>::iterator, bool> iter_1 =
      tester.s21_map_four.insert({5, 2});
  std::pair<std::map<int, int>::iterator, bool> iter_2 =
      tester.std_map_four.insert({5, 2});
  EXPECT_EQ((*(iter_1.first)).second, (*(iter_2.first)).second);
  EXPECT_TRUE(iter_1.second == iter_2.second);
}

TEST(Map, function_insert_with_duplicate) {
  TestMap tester;
  std::pair<s21::map<int, int>::iterator, bool> iter_1 =
      tester.s21_map_four.insert({1, 2});
  std::pair<std::map<int, int>::iterator, bool> iter_2 =
      tester.std_map_four.insert({1, 2});
  EXPECT_TRUE(iter_1.second == iter_2.second);
}

TEST(Map, function_insert_key_value_without_duplicate) {
  TestMap tester;
  std::pair<s21::map<int, int>::iterator, bool> iter_1 =
      tester.s21_map_four.insert(7, 7);
  std::pair<std::map<int, int>::iterator, bool> iter_2 =
      tester.std_map_four.insert({7, 7});
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ((*(iter_1.first)).second, (*(iter_2.first)).second);
  EXPECT_TRUE(iter_1.second == iter_2.second);
}

TEST(Map, function_insert_key_value_with_duplicate) {
  TestMap tester;
  std::pair<s21::map<int, int>::iterator, bool> iter_1 =
      tester.s21_map_four.insert(1, 7);
  std::pair<std::map<int, int>::iterator, bool> iter_2 =
      tester.std_map_four.insert({1, 7});
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_TRUE(iter_1.second == iter_2.second);
}
TEST(Map, function_insert_or_assign_value) {
  s21::map<int, int> m1({{1, 3}, {4, 2}});
  std::map<int, int> m2({{1, 3}, {4, 2}});
  std::pair<s21::map<int, int>::iterator, bool> it1 = m1.insert_or_assign(5, 2);
  std::pair<std::map<int, int>::iterator, bool> it2 = m2.insert_or_assign(5, 2);
  ASSERT_TRUE(it1.second == it2.second);
}

TEST(Map, function_insert_or_assign) {
  s21::map<int, int> m1({{1, 3}, {4, 2}});
  std::map<int, int> m2({{1, 3}, {4, 2}});
  std::pair<s21::map<int, int>::iterator, bool> it1 = m1.insert_or_assign(1, 2);
  std::pair<std::map<int, int>::iterator, bool> it2 = m2.insert_or_assign(1, 2);
  ASSERT_EQ((*(it1.first)).second, (*(it2.first)).second);
  ASSERT_TRUE(it1.second == it2.second);
}
TEST(Map, function_insert_s) {
  s21::map<int, int> m1({{1, 3}, {4, 2}});
  std::pair<s21::map<int, int>::iterator, bool> it1 = m1.insert(5, 2);
  ASSERT_EQ((*(it1.first)).second, 2);
  ASSERT_TRUE(it1.second);
}

TEST(Map, function_at) {
  s21::map<int, int> m1({{1, 3}, {4, 2}});
  std::map<int, int> m2({{1, 3}, {4, 2}});
  ASSERT_EQ(m1.at(1), m2.at(1));
}
TEST(Map, function_erase) {
  s21::map<int, int> m1({{1, 3}, {4, 2}});
  std::map<int, int> m2({{1, 3}, {4, 2}});
  m1.erase(m1.begin());
  m2.erase(m2.begin());
  ASSERT_EQ(m1[1], m2[1]);
}

TEST(Map, function_ontains) {
  s21::map<int, int> s1({{1, 3}, {4, 2}});
  ASSERT_TRUE(s1.contains(1));
  ASSERT_TRUE(s1.contains(4));
  ASSERT_FALSE(s1.contains(3));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
