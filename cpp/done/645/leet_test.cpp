#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{1,2,2,4};
  vector<int> expect{2,3};

  EXPECT_EQ(sol.findErrorNums(nums), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums{2,7,1,6, 8,2,3,4};
  vector<int> expect{2,5};

  EXPECT_EQ(sol.findErrorNums(nums), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums{2,2};
  vector<int> expect{2,1};

  EXPECT_EQ(sol.findErrorNums(nums), expect);
}

