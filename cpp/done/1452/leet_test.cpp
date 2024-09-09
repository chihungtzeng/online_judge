#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<string>> favoriteCompanies = {{"leetcode","google","facebook"},{"google","microsoft"},{"google","facebook"},{"google"},{"amazon"}};
  vector<int> expect{0,1,4};

  EXPECT_EQ(sol.peopleIndexes(favoriteCompanies), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<string>> favoriteCompanies = {{"leetcode","google","facebook"},{"leetcode","amazon"},{"facebook","google"}};
  vector<int> expect{0,1};

  EXPECT_EQ(sol.peopleIndexes(favoriteCompanies), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<string>> favoriteCompanies = {{"leetcode"},{"google"},{"facebook"},{"amazon"}};
  vector<int> expect{0,1,2,3};

  EXPECT_EQ(sol.peopleIndexes(favoriteCompanies), expect);
}

