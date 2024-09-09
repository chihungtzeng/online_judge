#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> vs;
  srand(time(nullptr));

  for (int i = 0; i < 20; i++)
  {
    vs.push_back(rand() % 100);
  }
  LOG(INFO) << vs;
  vector<int> ans;
  for (int i = 0; i < vs.size(); i++)
  {
    ans.push_back(sol.kth(vs, i + 1));
    LOG(INFO) << i + 1 << "th val: " << ans.back();
  }
  LOG(INFO) << ans;
  //  EXPECT_EQ(sol.trailingZeroes(3), 0);
  sort(vs.begin(), vs.end());
  LOG(INFO) << vs;
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> vs{ 51, 15, 40, 35, 42, 4, 67, 48, 89, 2, 55, 21, 97, 82, 17, 26, 78, 18, 51, 39 };
  vector<int> ans;
  for (int i = 0; i < vs.size(); i++)
  {
    ans.push_back(sol.kth(vs, i + 1));
  }
  // take care of 13th
  sort(vs.begin(), vs.end());
  LOG(INFO) << vs;
  EXPECT_EQ(vs, ans);
}

