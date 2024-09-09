#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
 MyCircularDeque* obj = new MyCircularDeque(3);
 EXPECT_EQ(obj->isEmpty(), true);
 EXPECT_EQ(obj->isFull(), false);

 EXPECT_EQ(obj->insertLast(1), true);
 EXPECT_EQ(obj->isEmpty(), false);
 EXPECT_EQ(obj->isFull(), false);


 EXPECT_EQ(obj->insertLast(2), true);
 EXPECT_EQ(obj->insertFront(3), true);
 EXPECT_EQ(obj->insertFront(4), false);
 EXPECT_EQ(obj->getRear(), 2);
 EXPECT_EQ(obj->isFull(), true);
 EXPECT_EQ(obj->deleteLast(), true);
 EXPECT_EQ(obj->insertFront(4), true);
 EXPECT_EQ(obj->getFront(), 4);
 EXPECT_EQ(obj->isFull(), true);

 EXPECT_EQ(obj->deleteFront(), true);
 EXPECT_EQ(obj->getFront(), 3);
 EXPECT_EQ(obj->deleteFront(), true);
 EXPECT_EQ(obj->getFront(), 1);
 EXPECT_EQ(obj->deleteFront(), true);
 EXPECT_EQ(obj->deleteFront(), false);
 EXPECT_EQ(obj->isEmpty(), true);


 delete obj;
}

