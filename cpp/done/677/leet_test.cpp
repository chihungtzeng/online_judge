#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  MapSum* obj = new MapSum();
  obj->insert("apple", 3);
  EXPECT_EQ(obj->sum("ap"), 3);
  obj->insert("app", 2);
  EXPECT_EQ(obj->sum("ap"), 5);
  EXPECT_EQ(obj->sum("apple"), 3);
  EXPECT_EQ(obj->sum("applee"), 0);
  EXPECT_EQ(obj->sum(""), 5);
  delete obj;
}

TEST(kk, t2) {
  MapSum* obj = new MapSum();
  obj->insert("aa", 3);
  EXPECT_EQ(obj->sum("a"), 3);
  obj->insert("aa", 2);
  EXPECT_EQ(obj->sum("a"), 2);
  delete obj;
}

