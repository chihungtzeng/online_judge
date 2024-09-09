#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.beautySum("aabcb"), 5);
  EXPECT_EQ(sol.beautySum("aabcbaa"), 17);
  EXPECT_EQ(sol.beautySum("consistsofonlylowercaseenglishletters"), 1214);
}

