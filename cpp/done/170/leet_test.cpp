#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  TwoSum* obj = new TwoSum();
  obj->add(1);
  obj->add(1);
  EXPECT_EQ(obj->find(0), false);
  EXPECT_EQ(obj->find(1), false);
  EXPECT_EQ(obj->find(2), true);
  obj->add(-1);
  EXPECT_EQ(obj->find(0), true);
  EXPECT_EQ(obj->find(1), false);
  EXPECT_EQ(obj->find(-2), false);
  obj->add(-1);
  EXPECT_EQ(obj->find(-2), true);
  delete obj;
}

TEST(kk, t2) {
  TwoSum* obj = new TwoSum();
  obj->add(1);
  EXPECT_EQ(obj->find(-2147483648), false);
  delete obj;
}

