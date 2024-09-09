#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> target = {9, 3, 5};
  EXPECT_EQ(sol.isPossible(target), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> target = {1, 1, 1, 2};
  EXPECT_EQ(sol.isPossible(target), false);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> target = {8, 5};
  EXPECT_EQ(sol.isPossible(target), true);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> target = {1, 1000000000};
  EXPECT_EQ(sol.isPossible(target), true);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> target = {1, 1000000000, 1};
  EXPECT_EQ(sol.isPossible(target), false);
}

#if 1
TEST(kk, t6) {
  Solution sol;
  vector<int> target = {1, 1000000001, 1};
  EXPECT_EQ(sol.isPossible(target), true);
}

TEST(kk, t7) {
  Solution sol;
  vector<int> target = {2};
  EXPECT_EQ(sol.isPossible(target), false);
}

TEST(kk, t7_1) {
  Solution sol;
  vector<int> target = {1};
  EXPECT_EQ(sol.isPossible(target), true);
}




#endif
