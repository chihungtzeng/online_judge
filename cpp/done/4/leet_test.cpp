#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums1 = {1,3}, nums2 = {2};
  EXPECT_EQ(sol.findMedianSortedArrays(nums1, nums2), 2.0);
  LOG(INFO) << "actual: " << sol.findMedianSortedArrays(nums1, nums2);
}

TEST(kk, t1_2) {
  Solution sol;
  vector<int> nums1 = {1,7}, nums2 = {};
  EXPECT_EQ(sol.findMedianSortedArrays(nums1, nums2), 4.0);
}

TEST(kk, t1_3) {
  Solution sol;
  vector<int> nums1 = {}, nums2 = {7};
  EXPECT_EQ(sol.findMedianSortedArrays(nums1, nums2), 7.0);
}


TEST(kk, t2) {
  Solution sol;
  vector<int> nums1 = {1,2}, nums2 = {3,4};
  EXPECT_EQ(sol.findMedianSortedArrays(nums1, nums2), 2.5);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums1, nums2, nums3;

  srand(time(nullptr));
  for(int i=0; i<1000; i++)
  {
    nums1.push_back(rand() % 10000 - 5000);
    nums2.push_back(rand() % 10000 - 5000);
    nums3.push_back(nums1.back());
    nums3.push_back(nums2.back());
  }

  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());
  sort(nums3.begin(), nums3.end());

  int n = nums3.size();
  EXPECT_EQ(sol.findMedianSortedArrays(nums1, nums2), (nums3[n/2] + nums3[n/2 - 1]) /2.0);
}

TEST(kk, t3_2) {
  Solution sol;
  vector<int> nums1, nums2, nums3;

  srand(time(nullptr));
  for(int i=0; i<1000; i++)
  {
    nums1.push_back(rand() % 10000 - 5000);
    nums2.push_back(rand() % 10000 - 5000);
  }
  nums2.pop_back();
  for(auto v: nums1) nums3.push_back(v);
  for(auto v: nums2) nums3.push_back(v);

  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());
  sort(nums3.begin(), nums3.end());

  int n = nums3.size();
  EXPECT_EQ(sol.findMedianSortedArrays(nums1, nums2), (double) nums3[n/2] );
}

