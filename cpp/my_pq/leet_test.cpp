#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  vector<int> vals{ 5, 1, 8, 4, 0, 7, 3, 10, 6, 2, 9 };
  auto pq = PQ(vals);
  while (!pq.empty())
  {
    auto v = pq.top();
    LOG(INFO) << "top " << v;
    pq.pop();
  }
  for (int i = 0, j = 5; i < 20; i++)
  {
    pq.push(j);
    LOG(INFO) << "push " << j;
    j = (j + 11) % 20;
  }

  while (!pq.empty())
  {
    auto v = pq.top();
    LOG(INFO) << "top " << v;
    pq.pop();
  }
}

