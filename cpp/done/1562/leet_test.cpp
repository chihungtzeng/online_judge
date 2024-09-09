#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr{3,5,1,2,4};
  EXPECT_EQ(sol.findLatestStep(arr, 1), 4);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> arr{3,1,5,4,2};
  EXPECT_EQ(sol.findLatestStep(arr, 2), -1);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr{1};
  EXPECT_EQ(sol.findLatestStep(arr, 1), 1);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> arr{2,1};
  EXPECT_EQ(sol.findLatestStep(arr, 2), 2);
}

