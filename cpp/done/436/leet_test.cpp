#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> intervals{{1, 2}};
  vector<int> expect{-1};

  EXPECT_EQ(sol.findRightInterval(intervals), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> intervals{{3, 4}, {2, 3}, {1, 2}};
  vector<int> expect{-1, 0, 1};

  EXPECT_EQ(sol.findRightInterval(intervals), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> intervals{{1, 4}, {2, 3}, {3, 4}};
  vector<int> expect{-1, 2, -1};

  EXPECT_EQ(sol.findRightInterval(intervals), expect);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<int>> intervals{{4, 5}, {2, 3}, {1,2}};
  vector<int> expect{-1, 0, 1};

  EXPECT_EQ(sol.findRightInterval(intervals), expect);
}

TEST(kk, t5) {
  Solution sol;
  vector<vector<int>> intervals{{1,12},{2,9},{3,10},{13,14},{15,16},{16,17}};
  vector<int> expect{3,3,3,4,5,-1};

  EXPECT_EQ(sol.findRightInterval(intervals), expect);
}

