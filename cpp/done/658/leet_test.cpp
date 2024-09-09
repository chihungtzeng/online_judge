#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr{1,2,3,4,5};
  int k = 4, x = 3;
  vector<int> expect{1,2,3,4};
  EXPECT_EQ(sol.findClosestElements(arr, k, x), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> arr{1,2,3,4,5};
  int k = 4, x = -1;
  vector<int> expect{1,2,3,4};
  EXPECT_EQ(sol.findClosestElements(arr, k, x), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr{1,2,3,4,100, 101};
  int k = 4, x = 99;
  vector<int> expect{3,4,100,101};
  EXPECT_EQ(sol.findClosestElements(arr, k, x), expect);
}

