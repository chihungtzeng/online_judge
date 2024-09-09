#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  std::vector<int> nums1{1,7,11};
  std::vector<int> nums2{2,4,6};
  std::vector<std::vector<int>> expect{{1, 2}, {1, 4}, {1, 6}};

  EXPECT_EQ(sol.kSmallestPairs(nums1, nums2, 3), expect);
}

TEST(kk, t2) {
  Solution sol;
  std::vector<int> nums1;
  std::vector<int> nums2;
  std::vector<std::vector<int>> expect;

  EXPECT_EQ(sol.kSmallestPairs(nums1, nums2, 3).size(), 0);
}

TEST(kk, t2_1) {
  Solution sol;
  std::vector<int> nums1{3,5,7,9};
  std::vector<int> nums2;
  std::vector<std::vector<int>> expect;

  EXPECT_EQ(sol.kSmallestPairs(nums1, nums2, 3).size(), 0);
}



TEST(kk, t3) {
  Solution sol;
  std::vector<int> nums1{1,1,2};
  std::vector<int> nums2{1,2,3};
  std::vector<std::vector<int>> expect{{1,1},{1,1}};

  EXPECT_EQ(sol.kSmallestPairs(nums1, nums2, 2), expect);
}

TEST(kk, t4) {
  Solution sol;
  std::vector<int> nums1{1,2};
  std::vector<int> nums2{3};
  std::vector<std::vector<int>> expect{{1,3},{2,3}};

  EXPECT_EQ(sol.kSmallestPairs(nums1, nums2, 200), expect);
}


TEST(kk, t5) {
  Solution sol;
  std::vector<int> nums1 {1,2,4,5,6};
  std::vector<int> nums2 {3,5,7,9};

  std::vector<std::vector<int>> expect{{1,3},{2,3},{1,5}};

  EXPECT_EQ(sol.kSmallestPairs(nums1, nums2, 3), expect);
}


