#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> courses{{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};

  EXPECT_EQ(sol.scheduleCourse(courses), 3);
}

