#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.daysBetweenDates("2019-06-29", "2019-06-30"), 1);
  EXPECT_EQ(sol.daysBetweenDates("2020-01-15", "2019-12-31"), 15);
  EXPECT_EQ(sol.daysBetweenDates("1971-01-15", "2100-12-31"), 47467);
  EXPECT_EQ(sol.daysBetweenDates("1971-01-15", "2100-01-30"), 47132);
  EXPECT_EQ(sol.daysBetweenDates("1971-01-15", "2100-03-20"), 47181);
  EXPECT_EQ(sol.days_since(1,1,1), 1);
  EXPECT_EQ(sol.days_since(1,3,1), 31+28 + 1);
  EXPECT_EQ(sol.days_since(4,3,1), 365*3 + 31+29 + 1);
  EXPECT_EQ(sol.days_since(4,1,1), 365*3 + 1);
}

