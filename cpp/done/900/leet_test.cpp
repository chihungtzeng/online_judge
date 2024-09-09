#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  vector<int> A{3,8,0,9,2,5};
  RLEIterator* obj = new RLEIterator(A);
  EXPECT_EQ(obj->next(2), 8);
  EXPECT_EQ(obj->next(1), 8);
  EXPECT_EQ(obj->next(1), 5);
  EXPECT_EQ(obj->next(2), -1);
  delete obj;
}

