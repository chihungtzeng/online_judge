#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<string>> equations{{"a", "b"}, {"b", "c"}};
  vector<double> values{2.0, 3.0};
  vector<vector<string>> queries{{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
  vector<double> expect{6.0, 0.5, -1.0, 1.0, -1.0};

  EXPECT_EQ(sol.calcEquation(equations, values, queries), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<string>> equations{{"a","b"},{"c","d"}};
  vector<double> values{1.0,1.0};
  vector<vector<string>> queries {{"a","c"},{"b","d"},{"b","a"},{"d","c"}};
  vector<double> expect{-1.00000,-1.00000,1.00000,1.00000};

  EXPECT_EQ(sol.calcEquation(equations, values, queries), expect);
}

