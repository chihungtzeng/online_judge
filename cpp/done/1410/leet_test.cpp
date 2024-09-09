#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(
      sol.entityParser("&amp; is an HTML entity but &ambassador; is not."),
      "& is an HTML entity but &ambassador; is not.");
  EXPECT_EQ(sol.entityParser("and I quote: &quot;...&quot;"),
            "and I quote: \"...\"");
  EXPECT_EQ(sol.entityParser("Stay home! Practice on Leetcode :)"),
            "Stay home! Practice on Leetcode :)");

  EXPECT_EQ(sol.entityParser("x &gt; y &amp;&amp; x &lt; y is always false"),
            "x > y && x < y is always false");
  EXPECT_EQ(sol.entityParser("leetcode.com&frasl;problemset&frasl;all"),
            "leetcode.com/problemset/all");
}

