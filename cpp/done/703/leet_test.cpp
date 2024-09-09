#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  vector<int> nums{4,5,8,2};
  int k=3;
  KthLargest* obj = new KthLargest(k, nums);

  EXPECT_EQ(obj->add(3), 4);
  EXPECT_EQ(obj->add(5), 5);
  EXPECT_EQ(obj->add(10), 5);
  EXPECT_EQ(obj->add(9), 8);
  EXPECT_EQ(obj->add(4), 8);
  delete obj;
}

TEST(kk, t2) {
  vector<int> nums{4,5};
  int k=3;
  KthLargest* obj = new KthLargest(k, nums);

  EXPECT_EQ(obj->add(8), 4);
  EXPECT_EQ(obj->add(2), 4);
  EXPECT_EQ(obj->add(3), 4);
  EXPECT_EQ(obj->add(5), 5);
  EXPECT_EQ(obj->add(10), 5);
  EXPECT_EQ(obj->add(9), 8);
  EXPECT_EQ(obj->add(4), 8);
  delete obj;
}

