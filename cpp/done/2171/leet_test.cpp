#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> beans = { 4, 1, 6, 5 };
  EXPECT_EQ(sol.minimumRemoval(beans), 4);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> beans = { 2, 10, 3, 2 };
  EXPECT_EQ(sol.minimumRemoval(beans), 7);
}

TEST(kk, t3)
{
  Solution sol;
  vector<int> beans = { 918, 625, 705, 507, 167, 529, 751, 783, 701, 73,  979, 160, 982, 834, 438,
                        813, 755, 163, 503, 527, 4,   443, 74,  848, 133, 223, 961, 870, 557, 288 };
  EXPECT_EQ(sol.minimumRemoval(beans), 6757);
}

TEST(kk, t4)
{
  Solution sol;
  vector<int> beans;
  for(int i=0; i<100000; i++)
  {
    beans.push_back(100000);
  }
  EXPECT_EQ(sol.minimumRemoval(beans), 0);
}

