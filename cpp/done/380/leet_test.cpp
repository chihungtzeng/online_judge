#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
 RandomizedSet* obj = new RandomizedSet();
 EXPECT_TRUE(obj->insert(1));
 EXPECT_FALSE(obj->remove(2));
 EXPECT_TRUE(obj->insert(2));
 auto ret = obj->getRandom();
 EXPECT_TRUE(ret == 1 || ret == 2);
 EXPECT_TRUE(obj->remove(1));
 EXPECT_EQ(obj->getRandom(), 2);
 EXPECT_EQ(obj->getRandom(), 2);
 EXPECT_EQ(obj->getRandom(), 2);
 EXPECT_EQ(obj->getRandom(), 2);
 EXPECT_EQ(obj->getRandom(), 2);
 EXPECT_EQ(obj->getRandom(), 2);
 delete obj;
}

TEST(kk, t2) {
 RandomizedSet* obj = new RandomizedSet();
 for(int i=0; i<100000; i++){
  EXPECT_TRUE(obj->insert(i));
 }
 for(int i=0; i<100000; i++){
  obj->getRandom();
 }
 delete obj;
}

TEST(kk, t3) {
 RandomizedSet* obj = new RandomizedSet();
 EXPECT_FALSE(obj->remove(0));
 EXPECT_FALSE(obj->remove(0));
 EXPECT_TRUE(obj->insert(0));
 EXPECT_EQ(obj->getRandom(), 0);
 EXPECT_TRUE(obj->remove(0));
 EXPECT_TRUE(obj->insert(0));
 delete obj;
}

