#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  LRUCache* obj = new LRUCache(2);
  obj->put(1, 1);
  obj->put(2, 2);
  EXPECT_EQ(obj->get(1), 1);
  obj->put(3, 3);
  EXPECT_EQ(obj->get(2), -1);
  obj->put(4, 4);
  EXPECT_EQ(obj->get(1), -1);
  EXPECT_EQ(obj->get(3), 3);
  EXPECT_EQ(obj->get(4), 4);
  delete obj;
}

TEST(kk, t2) {
  LRUCache* obj = new LRUCache(2);
  obj->put(2, 1);
  obj->put(2, 2);
  EXPECT_EQ(obj->get(2), 2);
  obj->put(1, 1);
  obj->put(4, 1);
  EXPECT_EQ(obj->get(2), -1);
  delete obj;
}

TEST(kk, t3) {
  LRUCache* obj = new LRUCache(2);
  EXPECT_EQ(obj->get(2), -1);
  obj->put(2, 6);
  EXPECT_EQ(obj->get(1), -1);
  obj->put(1,5);
  obj->put(1, 2);
  EXPECT_EQ(obj->get(1), 2);
  EXPECT_EQ(obj->get(2), 6);
  delete obj;
}

TEST(kk, t4) {
  LRUCache* obj = new LRUCache(2);
  obj->put(1, 0);
  obj->put(2, 2);
  EXPECT_EQ(obj->get(1), 0);
  obj->put(3, 3);
  EXPECT_EQ(obj->get(2), -1);
  obj->put(4, 4);
  EXPECT_EQ(obj->get(1), -1);
  EXPECT_EQ(obj->get(3), 3);
  EXPECT_EQ(obj->get(4), 4);
  delete obj;
}
