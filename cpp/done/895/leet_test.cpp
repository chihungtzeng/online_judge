#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  FreqStack* obj = new FreqStack();
  obj->push(5);
  obj->push(7);
  obj->push(5);
  obj->push(7);
  obj->push(4);
  obj->push(5);
  EXPECT_EQ(obj->pop(), 5);
  EXPECT_EQ(obj->pop(), 7);
  EXPECT_EQ(obj->pop(), 5);
  EXPECT_EQ(obj->pop(), 4);
  delete obj;
}

TEST(kk, t2)
{
  FreqStack* obj = new FreqStack();
  for(int i=0; i<100; i++){
    obj->push(-1);
  }
  for(int i=0; i<=20000; i++){
    obj->push(i+1000);
  }
  for(int i=0; i<99; i++){
    EXPECT_EQ(obj->pop(), -1);
  }
  for(int i=0; i<=20000; i++){
    EXPECT_EQ(obj->pop(), 21000 - i);
  }
  EXPECT_EQ(obj->pop(), -1);
  delete obj;
}


TEST(kk, t3)
{
  FreqStack* obj = new FreqStack();
  obj->push(4);
  obj->push(0);
  obj->push(9);
  obj->push(3);
  obj->push(4);
  obj->push(2);
  EXPECT_EQ(obj->pop(), 4);
  obj->push(6);
  EXPECT_EQ(obj->pop(), 6);
  obj->push(1);
  EXPECT_EQ(obj->pop(), 1);
  obj->push(1);
  EXPECT_EQ(obj->pop(), 1);
  obj->push(4);
  EXPECT_EQ(obj->pop(), 4);
  EXPECT_EQ(obj->pop(), 2);
  EXPECT_EQ(obj->pop(), 3);
  EXPECT_EQ(obj->pop(), 9);
  EXPECT_EQ(obj->pop(), 0);
  EXPECT_EQ(obj->pop(), 4);
  delete obj;
  }
