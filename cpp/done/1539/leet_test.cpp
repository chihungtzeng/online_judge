#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr{2,3,4,7,11};

  EXPECT_EQ(sol.findKthPositive(arr, 5), 9);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> arr{1,2,3,4};

  EXPECT_EQ(sol.findKthPositive(arr, 2), 6);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr {1,10,21,22,25};

  EXPECT_EQ(sol.findKthPositive(arr, 12), 14);
}

