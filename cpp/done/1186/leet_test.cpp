#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr = {1,-2,0,3};
  EXPECT_EQ(sol.maximumSum(arr), 4);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> arr = {1,-2,-2,3};
  EXPECT_EQ(sol.maximumSum(arr), 3);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr = {-1,-1,-1,-1};
  EXPECT_EQ(sol.maximumSum(arr), -1);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> arr = {-1};
  EXPECT_EQ(sol.maximumSum(arr), -1);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> arr = {2,1,-2,-5,-2};

  EXPECT_EQ(sol.maximumSum(arr), 3);
}

