#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  int m = 3, n = 3, k = 5;
  EXPECT_EQ(sol.findKthNumber(m, n, k), 3);
}

TEST(kk, t2)
{
  Solution sol;
  int m = 2, n = 3, k = 6;
  EXPECT_EQ(sol.findKthNumber(m, n, k), 6);
}

TEST(kk, t3)
{
  Solution sol;
  int m = 5678, n = 123;
  int mn = m *n;
  vector<int> arr;
  for(int i=1; i<=m; i++)
  {
    for(int j=1; j<=n; j++)
    {
      arr.push_back(i*j);
    }
  }
  sort(arr.begin(), arr.end());
  for(int k=1; k<=mn; k+= 101)
  {
    int actual = sol.findKthNumber(m, n, k);
    if (actual != arr[k-1]) {
      LOG(INFO) << "k: "  << k << ", expect " << arr[k-1] << ", got " << actual;
    }
  }
}

