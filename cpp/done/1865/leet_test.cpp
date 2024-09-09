#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  vector<int> nums1{1, 1, 2, 2, 2, 3}, nums2{1, 4, 5, 2, 5, 4};
  FindSumPairs* obj = new FindSumPairs(nums1, nums2);
  EXPECT_EQ(obj->count(7), 8);
  obj->add(3, 2);
  EXPECT_EQ(obj->count(8), 2);
  EXPECT_EQ(obj->count(4), 1);
  obj->add(0, 1);
  obj->add(1, 1);
  EXPECT_EQ(obj->count(7), 11);
  delete obj;
}

