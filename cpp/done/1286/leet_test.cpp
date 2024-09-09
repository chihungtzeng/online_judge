#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {

 CombinationIterator* obj = new CombinationIterator("abc", 2);
 EXPECT_EQ(obj->next(), "ab");
 EXPECT_EQ(obj->hasNext(), true);
 EXPECT_EQ(obj->next(), "ac");
 EXPECT_EQ(obj->hasNext(), true);
 delete obj;
}

TEST(kk, t2) {
 CombinationIterator* obj = new CombinationIterator("ahijp", 2);
 EXPECT_EQ(obj->next(), "ah");
 EXPECT_EQ(obj->next(), "ai");
 EXPECT_EQ(obj->hasNext(), true);
 EXPECT_EQ(obj->next(), "aj");
 EXPECT_EQ(obj->hasNext(), true);
 EXPECT_EQ(obj->next(), "ap");
 EXPECT_EQ(obj->hasNext(), true);
 EXPECT_EQ(obj->next(), "hi");
 EXPECT_EQ(obj->next(), "hj");
 delete obj;
}

