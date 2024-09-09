#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> paths{"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)",
                       "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
  vector<vector<string>> expect{
      {"root/a/2.txt", "root/c/d/4.txt", "root/4.txt"},
      {"root/a/1.txt", "root/c/3.txt"}};

  EXPECT_EQ(sol.findDuplicate(paths), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<string> paths{
      "root/a 1.txt(abcd) 2.txt(efsfgh)", "root/c 3.txt(abdfcd)",
      "root/c/d 4.txt(efggdfh)"};
  vector<vector<string>> expect;

  EXPECT_EQ(sol.findDuplicate(paths), expect);
}

