#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr{1,2,3,4,7};
  EXPECT_EQ(sol.maxDistance(arr, 3), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> arr{5,4,3,2,1,1000000000};
  EXPECT_EQ(sol.maxDistance(arr, 2), 999999999);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr{79,74,57,22};
  EXPECT_EQ(sol.maxDistance(arr, 4), 5);
}

