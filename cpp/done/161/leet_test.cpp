#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {0,1,3,50,75}; int lower = 0, upper = 99;
  vector<string> expect{"2","4->49","51->74","76->99"};
  EXPECT_EQ(sol.findMissingRanges(nums, lower, upper), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {}; int lower = 1, upper = 1;
  vector<string> expect{"1"};
  EXPECT_EQ(sol.findMissingRanges(nums, lower, upper), expect);
}

TEST(kk, t3) {
  Solution sol;
   vector<int> nums = {}; int lower = -3, upper = -1;
  vector<string> expect{"-3->-1"};
  EXPECT_EQ(sol.findMissingRanges(nums, lower, upper), expect);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums = {-1}; int lower = -1, upper = -1;
  vector<string> expect{};
  EXPECT_EQ(sol.findMissingRanges(nums, lower, upper), expect);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> nums = {-1}; int lower = -2, upper = -1;
  vector<string> expect{"-2"};
  EXPECT_EQ(sol.findMissingRanges(nums, lower, upper), expect);
}

TEST(kk, t6) {
  Solution sol;
  vector<int> nums = {2147483647}; int lower = 0, upper = 2147483647;
  vector<string> expect{"0->2147483646"};
  EXPECT_EQ(sol.findMissingRanges(nums, lower, upper), expect);
}

