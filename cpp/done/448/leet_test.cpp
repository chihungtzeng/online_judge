#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{4,3,2,7,8,2,3,1};
  vector<int> expect{5,6};


  EXPECT_EQ(sol.findDisappearedNumbers(nums), expect);
}

