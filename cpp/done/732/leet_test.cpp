#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  MyCalendarThree* obj = new MyCalendarThree();

  EXPECT_EQ(obj->book(10, 20), 1);
  EXPECT_EQ(obj->book(50, 60), 1);
  EXPECT_EQ(obj->book(10, 40), 2);
  EXPECT_EQ(obj->book(5, 15), 3);
  EXPECT_EQ(obj->book(5, 10), 3);
  EXPECT_EQ(obj->book(25, 55), 3);
  delete obj;
}

