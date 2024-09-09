#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.countOfAtoms("H2O"), "H2O");
  EXPECT_EQ(sol.countOfAtoms("Mg(OH)2"), "H2MgO2");
  EXPECT_EQ(sol.countOfAtoms("K4(ON(SO3)2)2"), "K4N2O14S4");
}

