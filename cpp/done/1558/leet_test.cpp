#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{1, 5};
  EXPECT_EQ(sol.minOperations(nums), 5);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums{2, 2};
  EXPECT_EQ(sol.minOperations(nums), 3);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums{4, 2, 5};
  EXPECT_EQ(sol.minOperations(nums), 6);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums{3, 2, 2, 4};
  EXPECT_EQ(sol.minOperations(nums), 7);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> nums{2, 4, 8, 16};
  EXPECT_EQ(sol.minOperations(nums), 8);
}

TEST(kk, t6) {
  Solution sol;
  vector<int> nums{2,   3,   5,   7,   11,  13,  17,  19,  23,  29,
                   31,  37,  41,  43,  47,  53,  59,  61,  67,  71,
                   73,  79,  83,  89,  97,  101, 103, 107, 109, 113,
                   127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
                   179, 181, 191, 193, 197, 199, 200, 201, 202, 203};
  EXPECT_EQ(sol.minOperations(nums), 207);
}

