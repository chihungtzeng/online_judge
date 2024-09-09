#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
 ProductOfNumbers* obj = new ProductOfNumbers();
 obj->add(3);
 obj->add(0);
 obj->add(2);
 obj->add(5);
 obj->add(4);

 EXPECT_EQ(obj->getProduct(2), 20);
 EXPECT_EQ(obj->getProduct(3), 40);
 EXPECT_EQ(obj->getProduct(4), 0);
 obj->add(8);
 EXPECT_EQ(obj->getProduct(2), 32);
 delete obj;
}

