#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  std::vector<int> nums{3,6,9,1};
  EXPECT_EQ(sol.maximumGap(nums), 3);
}

TEST(kk, t2) {
  Solution sol;

  std::vector<int> nums{10};
  EXPECT_EQ(sol.maximumGap(nums), 0);
}

TEST(kk, t3) {
  Solution sol;

  std::vector<int> nums;
  EXPECT_EQ(sol.maximumGap(nums), 0);
}

TEST(kk, t4) {
  Solution sol;

  std::vector<int> nums{1, 10};
  EXPECT_EQ(sol.maximumGap(nums), 9);
}


