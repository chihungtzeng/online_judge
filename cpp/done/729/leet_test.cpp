#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
    MyCalendar* obj = new MyCalendar();
    EXPECT_EQ(obj->book(10, 20), true);
    EXPECT_EQ(obj->book(15, 25), false);
    EXPECT_EQ(obj->book(20, 30), true);
  delete obj;
}

