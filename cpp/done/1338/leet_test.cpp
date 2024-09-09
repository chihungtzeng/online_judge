#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr = {3,3,3,3,5,5,5,2,2,7};
  EXPECT_EQ(sol.minSetSize(arr), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> arr = {7,7,7,7,7,7};
  EXPECT_EQ(sol.minSetSize(arr), 1);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr = {1,9};
  EXPECT_EQ(sol.minSetSize(arr), 1);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> arr = {1000,1000,3,7};
  EXPECT_EQ(sol.minSetSize(arr), 1);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
  EXPECT_EQ(sol.minSetSize(arr), 5);
}

