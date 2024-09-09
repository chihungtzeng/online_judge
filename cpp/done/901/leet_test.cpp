#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  StockSpanner* obj = new StockSpanner();

  EXPECT_EQ(obj->next(100), 1);
  EXPECT_EQ(obj->next(80), 1);
  EXPECT_EQ(obj->next(60), 1);
  EXPECT_EQ(obj->next(70), 2);
  EXPECT_EQ(obj->next(60), 1);
  EXPECT_EQ(obj->next(75), 4);
  EXPECT_EQ(obj->next(85), 6);
  EXPECT_EQ(obj->next(85), 7);
  EXPECT_EQ(obj->next(85), 8);
  delete obj;
}


TEST(kk, t2) {
  StockSpanner* obj = new StockSpanner();
  EXPECT_EQ(obj->next(100), 1);
  EXPECT_EQ(obj->next(100), 2);
  EXPECT_EQ(obj->next(100), 3);
  delete obj;
}


