#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
    MyCalendarTwo* obj = new MyCalendarTwo();
     EXPECT_EQ(obj->book(10, 20), true);
     EXPECT_EQ(obj->book(50, 60), true);
     EXPECT_EQ(obj->book(10, 40), true);
     EXPECT_EQ(obj->book(5, 15), false);
     EXPECT_EQ(obj->book(5, 10), true);
     EXPECT_EQ(obj->book(25, 55), true);
     delete obj;

}

