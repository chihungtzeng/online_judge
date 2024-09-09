#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
   AllOne* obj = new AllOne();
   obj->inc("apple");
   obj->dec("apple");
   EXPECT_EQ(obj->getMaxKey(), "");
   EXPECT_EQ(obj->getMinKey(), "");

   obj->inc("apple");
   obj->inc("apple");
   obj->inc("apple");
   obj->inc("lemon");
   obj->inc("lemon");

   EXPECT_EQ(obj->getMaxKey(), "apple");
   EXPECT_EQ(obj->getMinKey(), "lemon");

   obj->dec("lemon");
   obj->dec("lemon");

   EXPECT_EQ(obj->getMaxKey(), "apple");
   EXPECT_EQ(obj->getMinKey(), "apple");

   delete obj;
}

