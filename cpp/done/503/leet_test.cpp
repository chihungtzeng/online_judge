#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{1,2,1};
  vector<int> expect{2,-1,2};

  EXPECT_EQ(sol.nextGreaterElements(nums), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums{  3,1,4,1,5,9, 2,6};
  vector<int> expect{4,4,5,5,9,-1,6,9};

  EXPECT_EQ(sol.nextGreaterElements(nums), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums{  2,7,1,8,2,8};
  vector<int> expect{7,8,8,-1,8,-1};

  EXPECT_EQ(sol.nextGreaterElements(nums), expect);
}

