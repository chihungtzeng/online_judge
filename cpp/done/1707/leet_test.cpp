#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {0, 1, 2, 3, 4};
  vector<vector<int>> queries = {{3, 1}, {1, 3}, {5, 6}};
  vector<int> expect{3, 3, 7};
  EXPECT_EQ(sol.maximizeXor(nums, queries), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {5, 2, 4, 6, 6, 3};
  vector<vector<int>> queries = {{12, 4}, {8, 1}, {6, 3}};
  vector<int> expect{15, -1, 5};
  EXPECT_EQ(sol.maximizeXor(nums, queries), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {536870912, 0, 534710168, 330218644, 142254206};
  vector<vector<int>> queries = {{558240772, 1000000000},
                                 {307628050, 1000000000},
                                 {3319300, 1000000000},
                                 {2751604, 683297522},
                                 {214004, 404207941}};
  vector<int> expect{1050219420, 844498962, 540190212, 539622516, 330170208};
  EXPECT_EQ(sol.maximizeXor(nums, queries), expect);
}

