#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<string>> paths =
  { {"London", "New York"},
    {"New York", "Lima"},
    {"Lima", "Sao Paulo"} };

  EXPECT_EQ(sol.destCity(paths), "Sao Paulo");
}
