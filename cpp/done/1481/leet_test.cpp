#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr = {5,5,4};
  int k = 1;

  EXPECT_EQ(sol.findLeastNumOfUniqueInts(arr, k), 1);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> arr = {4,3,1,1,3,3,2};
  int k = 3;

  EXPECT_EQ(sol.findLeastNumOfUniqueInts(arr, k), 2);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr = {2,4,1,8,3,5,1,3};
  int k = 3;

  EXPECT_EQ(sol.findLeastNumOfUniqueInts(arr, k), 3);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> arr = {2,1,1,3,3,3};
  int k = 3;
  EXPECT_EQ(sol.findLeastNumOfUniqueInts(arr, k), 1);
}

