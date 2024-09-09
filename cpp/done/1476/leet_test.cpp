#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  vector<vector<int>> rect{{1, 2, 1}, {4, 3, 4}, {3, 2, 1}, {1, 1, 1}};
  SubrectangleQueries* obj = new SubrectangleQueries(rect);
  EXPECT_EQ(obj->getValue(0, 2), 1);

  obj->updateSubrectangle(0, 0, 3, 2, 5);
  EXPECT_EQ(obj->getValue(0, 2), 5);
  EXPECT_EQ(obj->getValue(3, 1), 5);
  obj->updateSubrectangle(3, 0, 3, 2, 10);
  EXPECT_EQ(obj->getValue(3, 1), 10);
  EXPECT_EQ(obj->getValue(0, 2), 5);

  delete obj;
}

