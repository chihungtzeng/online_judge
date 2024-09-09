#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19}, arr2 = {2,1,4,3,9,6};
  vector<int> expect{2,2,2,1,4,3,3,9,6,7,19};
  EXPECT_EQ(sol.relativeSortArray(arr1, arr2), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> arr1 = {28,6,22,8,44,17}, arr2 = {22,28,8,6};
  vector<int> expect{22,28,8,6,17,44};
  EXPECT_EQ(sol.relativeSortArray(arr1, arr2), expect);
}

