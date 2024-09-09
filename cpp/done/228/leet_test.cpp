#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  std::vector<int> nums{0,1,2,4,5,7};
  std::vector<string> expect{"0->2","4->5","7"};
  EXPECT_EQ(sol.summaryRanges(nums), expect);
}

TEST(kk, t2) {
  Solution sol;
  std::vector<int> nums{0,2,3,4,6,8,9};
  std::vector<string> expect{"0","2->4","6","8->9"};
  EXPECT_EQ(sol.summaryRanges(nums), expect);
}

TEST(kk, t3) {
  Solution sol;
  std::vector<int> nums;
  EXPECT_EQ(sol.summaryRanges(nums).size(), 0);
}

TEST(kk, t4) {
  Solution sol;
  std::vector<int> nums{9};
  std::vector<string> expect{"9"};
  EXPECT_EQ(sol.summaryRanges(nums), expect);
}

TEST(kk, t5) {
  Solution sol;
  std::vector<int> nums{1,3,5,79};
  std::vector<string> expect{"1", "3", "5", "79"};
  EXPECT_EQ(sol.summaryRanges(nums), expect);
}

TEST(kk, t6) {
  Solution sol;
  std::vector<int> nums{79,80,81,82};
  std::vector<string> expect{"79->82"};
  EXPECT_EQ(sol.summaryRanges(nums), expect);
}


