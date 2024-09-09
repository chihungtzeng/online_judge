#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  string s = "(name)is(age)yearsold";
  vector<vector<string>> knowledge = {{"name", "bob"}, {"age", "two"}};
  EXPECT_EQ(sol.evaluate(s, knowledge), "bobistwoyearsold");
}

TEST(kk, t2) {
  Solution sol;
  string s = "hi(name)";
  vector<vector<string>> knowledge = {{"a", "b"}};
  EXPECT_EQ(sol.evaluate(s, knowledge), "hi?");
}

TEST(kk, t3) {
  Solution sol;
  string s = "(a)(a)(a)aaa";
  vector<vector<string>> knowledge = {{"a", "yes"}};
  EXPECT_EQ(sol.evaluate(s, knowledge), "yesyesyesaaa");
}

TEST(kk, t4) {
  Solution sol;
  string s = "(a)(b)";
  vector<vector<string>> knowledge = {{"a", "b"}, {"b", "a"}};
  EXPECT_EQ(sol.evaluate(s, knowledge), "ba");
}

