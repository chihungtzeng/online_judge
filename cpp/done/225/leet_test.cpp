#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "leet.cpp"
#include <gtest/gtest.h>

TEST(kk, t1) {
  MyStack* stack = new MyStack();

  stack->push(1);
  stack->push(2);
  EXPECT_EQ(stack->top(), 2); // returns 2
  EXPECT_EQ(stack->pop(), 2); // returns 2
  EXPECT_FALSE(stack->empty());
  EXPECT_EQ(stack->pop(), 1); // returns 2
  EXPECT_TRUE(stack->empty());
  stack->push(1);
  stack->push(2);
  stack->push(3);
  EXPECT_FALSE(stack->empty());
  EXPECT_EQ(stack->top(), 3);
  EXPECT_EQ(stack->pop(), 3);
  stack->push(4);
  EXPECT_EQ(stack->pop(), 4);
  EXPECT_EQ(stack->pop(), 2);
  delete stack;
}

