#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
 MyCircularQueue* obj = new MyCircularQueue(3);
 EXPECT_EQ(obj->isEmpty(), true);
 EXPECT_EQ(obj->isFull(), false);

 EXPECT_EQ(obj->enQueue(1), true);
 EXPECT_EQ(obj->isEmpty(), false);
 EXPECT_EQ(obj->isFull(), false);

 EXPECT_EQ(obj->enQueue(2), true);
 EXPECT_EQ(obj->isEmpty(), false);
 EXPECT_EQ(obj->isFull(), false);

 EXPECT_EQ(obj->enQueue(3), true);
 EXPECT_EQ(obj->isEmpty(), false);
 EXPECT_EQ(obj->isFull(), true);

 EXPECT_EQ(obj->enQueue(4), false);
 EXPECT_EQ(obj->Rear(), 3);
 EXPECT_EQ(obj->isFull(), true);
 EXPECT_EQ(obj->deQueue(), true);
 EXPECT_EQ(obj->Front(), 2);
 EXPECT_EQ(obj->Rear(), 3);

 EXPECT_EQ(obj->enQueue(4), true);
 EXPECT_EQ(obj->Front(), 2);
 EXPECT_EQ(obj->Rear(), 4);

 EXPECT_EQ(obj->deQueue(), true);
 EXPECT_EQ(obj->deQueue(), true);
 EXPECT_EQ(obj->Rear(), 4);
 EXPECT_EQ(obj->Front(), 4);
 EXPECT_EQ(obj->deQueue(), true);
 EXPECT_EQ(obj->isEmpty(), true);
 EXPECT_EQ(obj->isFull(), false);

 delete obj;
}

