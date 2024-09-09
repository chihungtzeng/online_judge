#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
    MKAverage* obj = new MKAverage(3, 1);
  obj->addElement(3);
  obj->addElement(1);
  EXPECT_EQ(obj->calculateMKAverage(), -1);
  obj->addElement(10);
  EXPECT_EQ(obj->calculateMKAverage(), 3);
  obj->addElement(5);
  obj->addElement(5);
  obj->addElement(5);
  EXPECT_EQ(obj->calculateMKAverage(), 5);
  delete obj;
}

TEST(kk, t2) {
    MKAverage* obj = new MKAverage(3, 1);
  obj->addElement(17612);
  obj->addElement(74607);
  EXPECT_EQ(obj->calculateMKAverage(), -1);
  obj->addElement(8272);
  obj->addElement(33433);
  EXPECT_EQ(obj->calculateMKAverage(), 33433);
  obj->addElement(15456);
  obj->addElement(64938);
  EXPECT_EQ(obj->calculateMKAverage(), 33433);
  obj->addElement(99741);
  delete obj;
}

