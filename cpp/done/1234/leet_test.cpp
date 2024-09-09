#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.balancedString("QWER"), 0 );
  EXPECT_EQ(sol.balancedString("QQWE"), 1 );
  EXPECT_EQ(sol.balancedString("QQQW"), 2 );
  EXPECT_EQ(sol.balancedString("QQQQ"), 3 );
  EXPECT_EQ(sol.balancedString("QQRWQQWQWEQWWEQEERWQEQEQRQQWEWERWWQWWWEERERQWQERRQRWQEWQEEWW"), 6);
  /*
  srand(time(nullptr));
  string t;
  for(int i=0; i<60; i++){
    int idx = rand() % 4;
    t.push_back(sol.chs_[idx]);
  }
  LOG(INFO) << t;
  */
}


TEST(kk, t2) {
  vector<int> a[2];
  a[0] = {1,2,7, 9};
  LOG(INFO) << a[0];
  LOG(INFO) << a[1];
}
