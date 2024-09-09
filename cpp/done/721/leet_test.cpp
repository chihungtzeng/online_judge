#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<string>> accounts{
      {"John", "johnsmith@mail.com", "john00@mail.com"},
      {"John", "johnnybravo@mail.com"},
      {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
      {"Mary", "mary@mail.com"}};
  vector<vector<string>> expect{{"John", "john00@mail.com",
                                 "john_newyork@mail.com", "johnsmith@mail.com"},
                                {"John", "johnnybravo@mail.com"},
                                {"Mary", "mary@mail.com"}};

  EXPECT_EQ(sol.accountsMerge(accounts), expect);
}

