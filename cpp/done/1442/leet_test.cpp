#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr{2,3,1,6,7};
  EXPECT_EQ(sol.countTriplets(arr), 4);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> arr{1,1,1,1,1};
  EXPECT_EQ(sol.countTriplets(arr), 10);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr {2,3};
  EXPECT_EQ(sol.countTriplets(arr), 0);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> arr{1,3,5,7,9};
  EXPECT_EQ(sol.countTriplets(arr), 3);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> arr{7,11,12,9,5,2,7,17,22};
  EXPECT_EQ(sol.countTriplets(arr), 8);
}

