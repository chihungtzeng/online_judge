#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  LFUCache* cache = new LFUCache(2);

  cache->put(1, 1);
  cache->put(2, 2);
  EXPECT_EQ(cache->get(1), 1);   // returns 1
  cache->put(3, 3);              // evicts key 2
  EXPECT_EQ(cache->get(2), -1);  // returns -1 (not found)
  EXPECT_EQ(cache->get(3), 3);   // returns 3.
  cache->put(4, 4);              // evicts key 1.
  EXPECT_EQ(cache->get(1), -1);  // returns -1 (not found)
  EXPECT_EQ(cache->get(3), 3);   // returns 3
  EXPECT_EQ(cache->get(4), 4);   // returns 4
  delete cache;
}

TEST(kk, t2) {
  LFUCache* cache = new LFUCache(0);
  cache->put(0, 0);
  EXPECT_EQ(cache->get(0), -1);
  delete cache;
}
TEST(kk, t3) {
  LFUCache* cache = new LFUCache(10);
  cache->put(10, 13);
  cache->put(3, 17);
  cache->put(6, 11);
  cache->put(10, 5);
  cache->put(9, 10);
  EXPECT_EQ(cache->get(13), -1);
  cache->put(2, 19);
  EXPECT_EQ(cache->get(2), 19);
  EXPECT_EQ(cache->get(3), 17);
  cache->put(5, 25);
  EXPECT_EQ(cache->get(8), -1);
  cache->put(9, 22);
  cache->put(5, 5);
  cache->put(1, 30);
  EXPECT_EQ(cache->get(11), -1);
  cache->put(9, 12);
  EXPECT_EQ(cache->get(7), -1);
  EXPECT_EQ(cache->get(5), 5);
  EXPECT_EQ(cache->get(8), -1);
  EXPECT_EQ(cache->get(9), 12);
  cache->put(4, 30);
  cache->put(9, 3);
  EXPECT_EQ(cache->get(9), 3);
  EXPECT_EQ(cache->get(10), 5);
  EXPECT_EQ(cache->get(10), 5);
  cache->put(6, 14);
  cache->put(3, 1);
  EXPECT_EQ(cache->get(3), 1);
  cache->put(10, 11);
  EXPECT_EQ(cache->get(8), -1);
  cache->put(2, 14);
  EXPECT_EQ(cache->get(1), 30);
  EXPECT_EQ(cache->get(5), 5);
  EXPECT_EQ(cache->get(4), 30);
  cache->put(11, 4);
  cache->put(12, 24);
  cache->put(5, 18);
  EXPECT_EQ(cache->get(13), -1);
  cache->put(7, 23);
  EXPECT_EQ(cache->get(8), -1);
  EXPECT_EQ(cache->get(12), 24);
  cache->put(3, 27);
  cache->put(2, 12);
  EXPECT_EQ(cache->get(5), 18);
  cache->put(2, 9);
  cache->put(13, 4);
  cache->put(8, 18);
  cache->put(1, 7);
  EXPECT_EQ(cache->get(6), 14); // kkk
  cache->put(9, 29);
  cache->put(8, 21);
  EXPECT_EQ(cache->get(5), 18);
  cache->put(6, 30);
  cache->put(1, 12);
  EXPECT_EQ(cache->get(10), 11);
  cache->put(4, 15);
  cache->put(7, 22);
  cache->put(11, 26);
  cache->put(8, 17);
  cache->put(9, 29);
  EXPECT_EQ(cache->get(5), 18);
  cache->put(3, 4);
  cache->put(11, 30);
  EXPECT_EQ(cache->get(12), -1);
  cache->put(4, 29);
  EXPECT_EQ(cache->get(3), 4);
  EXPECT_EQ(cache->get(9), 29);
  EXPECT_EQ(cache->get(6), 30);
  cache->put(3, 4);
  EXPECT_EQ(cache->get(1), 12);
  EXPECT_EQ(cache->get(10), 11);
  cache->put(3, 29);
  cache->put(10, 28);
  cache->put(1, 20);
  cache->put(11, 13);
  EXPECT_EQ(cache->get(3), 29);
  cache->put(3, 12);
  cache->put(3, 8);
  cache->put(10, 9);
  cache->put(3, 26);
  EXPECT_EQ(cache->get(8), 17);
  EXPECT_EQ(cache->get(7), -1);
  EXPECT_EQ(cache->get(5), 18);
  cache->put(13, 17);
  cache->put(2, 27);
  cache->put(11, 15);
  EXPECT_EQ(cache->get(12), -1);
  cache->put(9, 19);
  cache->put(2, 15);
  cache->put(3, 16);
  EXPECT_EQ(cache->get(1), 20);
  cache->put(12, 17);
  cache->put(9, 1);
  cache->put(6, 19);
  EXPECT_EQ(cache->get(4), 29);
  EXPECT_EQ(cache->get(5), 18);
  EXPECT_EQ(cache->get(5), 18);
  cache->put(8, 1);
  cache->put(11, 7);
  cache->put(5, 2);
  cache->put(9, 28);
  EXPECT_EQ(cache->get(1), 20);
  cache->put(2, 2);
  cache->put(7, 4);
  cache->put(4, 22);
  cache->put(7, 24);
  cache->put(9, 26);
  cache->put(13, 28);
  cache->put(11, 26);
  delete cache;
}
