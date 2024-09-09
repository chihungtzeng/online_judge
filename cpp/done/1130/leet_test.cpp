#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr = {6, 2, 4};
  EXPECT_EQ(sol.mctFromLeafValues(arr), 32);
}

TEST(kk, t1_1) {
  Solution sol;
  vector<int> arr = {6, 2, 4,3};
  EXPECT_EQ(sol.mctFromLeafValues(arr), 44);
}


TEST(kk, t2) {
  Solution sol;
  vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 2, 7, 1, 8, 2, 8};
  EXPECT_EQ(sol.mctFromLeafValues(arr), 365);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr = {3, 14, 15, 9, 2, 6, 2, 7, 11, 8, 2, 8};
  EXPECT_EQ(sol.mctFromLeafValues(arr), 813);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> arr = {10, 15};
  EXPECT_EQ(sol.mctFromLeafValues(arr), 150);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> arr;
  for(int i=0; i<40; i++){
  arr.push_back(15);
  }
  EXPECT_EQ(sol.mctFromLeafValues(arr), 8775);
}

