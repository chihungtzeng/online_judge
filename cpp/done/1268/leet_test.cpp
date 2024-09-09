#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> products = {"mobile", "mouse", "moneypot", "monitor",
                             "mousepad"};
  string searchWord = "mouse";
  vector<vector<string>> expect{{"mobile", "moneypot", "monitor"},
                                {"mobile", "moneypot", "monitor"},
                                {"mouse", "mousepad"},
                                {"mouse", "mousepad"},
                                {"mouse", "mousepad"}};
  EXPECT_EQ(sol.suggestedProducts(products, searchWord), expect);
}

