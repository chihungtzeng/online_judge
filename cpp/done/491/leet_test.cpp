#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{4, 6, 7, 7};      
  vector<vector<int>> expect{{4, 6}, {4, 7}, {4, 6, 7}, {4, 6, 7, 7}, {6, 7}, {6, 7, 7}, {7,7}, {4,7,7}};
  sort(expect.begin(), expect.end());

  EXPECT_EQ(sol.findSubsequences(nums), expect);
}

