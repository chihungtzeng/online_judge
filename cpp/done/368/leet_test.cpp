#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{1, 2, 3};
  vector<int> expect{1, 2};
  auto actual = sol.largestDivisibleSubset(nums);
  sort(actual.begin(), actual.end());
  EXPECT_EQ(actual, expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums{1, 2, 4, 8};
  vector<int> expect{1, 2, 4, 8};
  auto actual = sol.largestDivisibleSubset(nums);
  sort(actual.begin(), actual.end());
  EXPECT_EQ(actual, expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums{101};
  vector<int> expect{101};
  auto actual = sol.largestDivisibleSubset(nums);
  sort(actual.begin(), actual.end());
  EXPECT_EQ(actual, expect);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums;
  vector<int> expect;
  auto actual = sol.largestDivisibleSubset(nums);
  sort(actual.begin(), actual.end());
  EXPECT_EQ(actual, expect);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> nums{3,1,4,1,1,1,1,1,1,5, 20};
  vector<int> expect{1,1,1,1,1,1,1,4, 20};
  auto actual = sol.largestDivisibleSubset(nums);
  sort(actual.begin(), actual.end());
  EXPECT_EQ(actual, expect);
}

