#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  string s = "1+-1i";
  auto c = sol.parse_complex(s);
  EXPECT_EQ(c.a_, 1);
  EXPECT_EQ(c.b_, -1);


  EXPECT_EQ(sol.complexNumberMultiply("1+1i", "1+1i"), "0+2i");
  EXPECT_EQ(sol.complexNumberMultiply("1+-1i", "1+-1i"), "0+-2i");
  EXPECT_EQ(sol.complexNumberMultiply("50+-37i", "-100+-100i"), "-8700+-1300i");
}

