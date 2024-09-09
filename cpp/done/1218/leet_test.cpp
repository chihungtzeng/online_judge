#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr = {1,2,3,4}; int difference = 1;
  EXPECT_EQ(sol.longestSubsequence(arr, difference), 4);
}

TEST(kk, t2) {
  Solution sol;
   vector<int> arr = {1,3,5,7}; int difference = 1;
  EXPECT_EQ(sol.longestSubsequence(arr, difference), 1);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr = {1,5,7,8,5,3,4,2,1}; int difference = -2;
  EXPECT_EQ(sol.longestSubsequence(arr, difference), 4);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> arr = {1}; int difference = -2;
  EXPECT_EQ(sol.longestSubsequence(arr, difference), 1);
}

