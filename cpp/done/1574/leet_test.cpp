#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr = {1,2,3,10,4,2,3,5};
  EXPECT_EQ(sol.findLengthOfShortestSubarray(arr), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> arr{5,4,3,2,1};
  EXPECT_EQ(sol.findLengthOfShortestSubarray(arr), 4);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr{1,2,3};
  EXPECT_EQ(sol.findLengthOfShortestSubarray(arr), 0);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> arr{1};
  EXPECT_EQ(sol.findLengthOfShortestSubarray(arr), 0);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> arr{13,0,14,7,18,18,18,16,8,15,20};
  EXPECT_EQ(sol.findLengthOfShortestSubarray(arr), 8);
}

