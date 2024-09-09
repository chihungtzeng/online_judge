#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  auto ipq = IPQ();

  ipq.push('a', 11);
  ipq.push('b', 7);
  ipq.push('c', 3);
  ipq.push('d', 10);
  ipq.push('e', 6);
  ipq.push('f', 2);
  ipq.push('g', 9);
  ipq.push('h', 5);
  ipq.push('i', 1);
  ipq.push('j', 8);
  ipq.push('k', 4);

  EXPECT_EQ(ipq.top().first, 1);

  ipq.pop();
  EXPECT_EQ(ipq.top().first, 2);

  ipq.update('f', 8);
  EXPECT_EQ(ipq.top().first, 3);
  ipq.update('f', 2);
  EXPECT_EQ(ipq.top().first, 2);

  ipq.update('x', 100);


  ipq.dump();
}
