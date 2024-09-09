#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.largestMerge("cabaa", "bcaaa"), "cbcabaaaaa");
  EXPECT_EQ(sol.largestMerge("abcabc", "abdcaba"), "abdcabcabcaba");
  EXPECT_EQ(sol.largestMerge("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
                             "bbbbbbbbbbbbbbbbbbbb"),
            "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
  string s1, s2;
  for (int i = 0; i < 3000; i++) {
    s1 += 'a';
    s2 += 'a';
  }
  auto ret = sol.largestMerge(s1, s2);
  EXPECT_EQ(ret.size(), 6000);
  for (int i = 0; i < ret.size(); i++) {
    EXPECT_EQ(ret[i], 'a');
  }
}

TEST(kk, t2) {
  Solution sol;

  string s1 =
      "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeqeeeee"
      "eeqeeeeeeeeeeeeqeeeeeeeeeeeeeeeqeeeeeeeqeqeeeeeeeeeqeeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeqqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
      "eeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeqe"
      "eeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeqeeeeeeeeeeeeeeqeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
      "eeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeqeqeeeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeqeee"
      "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
      "eqeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeee"
      "eeee";
  string s2 =
      "eeeqeeeeeeqeeeeeeeeeeeeqqeeqeeqqeeeqeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeee"
      "eeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeqeqeeeqeeeqeeeeeeeeeeeqeeeeqeqeeqeqee"
      "eeeqeeeqeeqeqeeeeeeeqeeqeqeeeeeeeeqeqeqeeeqeeeeqeeeeqeeeqeeeqeeeeeeqeeee"
      "eeeeeeeeqeeeeeeeeeeeeeeeeeqeeeeeeqeqqeqeeeeeeeeeqqeeeqeqeeqeeeeeeeeeqeee"
      "eqeeeqeeeeeqeeqeeeqqeeeeeeeeqeeeeeeeeeeeeeeqqeeqqqeeeqeeeeeeeeqeeqeeeeeq"
      "eqqeqeeqqeeeeeeeeeeqeqeqeeeeeqeeeeeeeeeqeqeeeeeeqqeeeqeeeeqeeeeeeqeeqeee"
      "eqeeeeeeeqeeqeeeeqeeqeeeeeeeeeeeqqeeeeeeeqeeeeeqeeqeeeeeeqeqeeeqeeeeeeee"
      "qeeeeeqeeeeeeeeeeqeqeeeeqqqeeeeeeqqqeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeqeeeee"
      "qeeqqeeqeeeeeeeeeeeeeeqeeqqeeeqeeeeeeeeeeeqeeeeqeeeeeeeeeeeeqeeeeeqeeeee"
      "eeeeeeqeqqeqqeeeeeeeeeeqqeeeeeeeeeqeeeeeeeeeeeeeeeeeeeqeeqqeeqeeeeeeqeeq"
      "eeeqeeeeeeqeeeeqeeqeqqqeeeqeeeeeeeeqqeeqeeeeqeeeeqeeeeeeeeeqqeeqqeeeeeeq"
      "eeeeeeeeqqeeeeeeeqeeeeeeeeeeeeqeeqeeeeeeeeeqeqeeqeeeeeeeeeeqeeqeeeeeeqee"
      "eqeeeeeeeeeqqeeqqeeeeeqeeeqeeeeeeeeeeeeeeeeqeqeeeeeeqeeqeeeqeeeqeeqeeqee"
      "eeeeqqeeeeeeeeeqqqeqqeeeqeeeeqqeeqqqeeeqeeeeqeeeeeeeeqeeeeqqqeeeeqeeeeqe"
      "qqeeqeeeeeeeeeeqeeeeeqqqeeqeeeeeeeeeeeqeeeeqeeeeeeeeeeqeeeqeeqeeeeeeqqeq"
      "eqqeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeqqeeeeeeeeeeeeeqqeqeqeeeeeeqeeeeqqqeeeq"
      "qeqqeeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeqeqeeeeeeeeeeeeeeeeeqqqeeqeeeeqeee"
      "eeqqeeeeeeeqeeeeeqqeeqqqqeeeeeeeeeeeqeeeeeeeeeeqeeqeeqeeeeeeeeeeeeqeqeeq"
      "eeeeeqqeeeeqqeeeqqeeeeeeeeeeqeeeqqeeeqeeeeeeqeeqqeeeqeqqeeeqeqeqqeeeqeee"
      "eeeeqeeeqeeeeeeqqeeqeeqeeeeeqeeeeqeeqeeqeqeeeeeeqeeeeqeeqeeeeeqeeqeqeeee"
      "eeqeeeeeeeeeeeeeeqeeqeeqeeeeeeeqeeqeeeeeeeqeeeeeeeeeeeeeqqeeeeeeqeeeeqee"
      "qeqeeeeeeeeqeqeqeeeeeeeqeqeeeeeeeeqeeeqeeeeeeeeeeeeeeqeeqeeeeeeeqeeeeeee"
      "eeeeqqeeeqeqqeeeeeeeqeeeeeqeeqeeeeqeeqeeeqeeeeeqqeeqeeeqeeeeeqeeeeeqeqee"
      "qqeeeeqeeeeeeeeeeeeeeeeeqeqeeeeqeeqeqeqeeeeeeeeqeeeeeqqeeeqeeeeqqeeeeeeq"
      "eeeeeeqeeeqeeeeeeeeeeqqeeeeeeeeqeeeqeeqeeeeeeqeeqeeeeeeeeqeqeeeeeeeeeeqe"
      "eeeeeeeqeqeqqeeeqeeeeqeeeeeeqeeeeqeeeqeeeeeeeeqeqqqqeqeeeeeqeeeqeeeeeeeq"
      "eqeeqeeeqeeeqeeeqeeeeeeqqqeqeeqeeeeeeqeqeqeeeeeeeeeqeqeeqeeqeeeeeeeeeqee"
      "eeeeeeeeeeeeeeeeeeeeqqqeeeeeeqeqeqeeqqeeeqqeeeqeeeeeqeeqeqeeqeeeeeeeeqee"
      "eqeeeeeeeqeeeeeqeqeqeqeqeeeeeeeeqeeeeqqqqeeeeqeeeeeeeeeeqeeqeeeqeeeqeeee"
      "qeeeeeeqqqqeeqeeqeeeeeeqqeeeeeeeeeqeqqeeeeeeqeeeeeqeqeeqqeeqqeeeeeeeqqqe"
      "eeeeeeeeqeeeeeqeqeeeeeeeqqqqqeeqeeqeeeeqeeeeeqeeeeeeeeqeqeeeeeeeeeeqeeqe"
      "eeeeeeeeeeeqqeeeqqeeeeeeeeeeqeqeeeqeeeeeeeqeeeeeeeeeeeeeeeqeeeeeeqqeeqeq"
      "eeeeeeeqeqeqqeeeqeeeqeeeqeeeeeqqeeeeeeqeeqqeeeeeeeeqeeeeeqeeeeeeeeeeeeee"
      "eqeeeeqqeeeeeqeeqeeeeqqeeeeeeeqeeeeqqeeeqeqeqeeeeeqeeeeeeqeqeeeeqeeeeqee"
      "eeqeeqeeeeqqeeeeeeeqeeeeeeeeeqeqeeeeeeeeeqeqeeeeeqeqeqqeqeqeeeqeeeqeqeqq"
      "qqqeeqeeeeqeeeqeeeqeeqeeeqeeeeeeqqeeeqeeeeeeeeeeeeeeqeqeeqeeeeqeeqeeeqqe"
      "eeeeeeeeeeeeqeeqeeeeeeeeeqeeeqqeeeeeeeeeeqeeeeeqeeeeeeeqeeeeeeeeeeeeeeee"
      "qeeeeee";

  string expect =
      "eeeqeeeeeeqeeeeeeeeeeeeqqeeqeeqqeeeqeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeee"
      "eeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeqeqeeeqeeeqeeeeeeeeeeeqeeeeqeqeeqeqee"
      "eeeqeeeqeeqeqeeeeeeeqeeqeqeeeeeeeeqeqeqeeeqeeeeqeeeeqeeeqeeeqeeeeeeqeeee"
      "eeeeeeeeqeeeeeeeeeeeeeeeeeqeeeeeeqeqqeqeeeeeeeeeqqeeeqeqeeqeeeeeeeeeqeee"
      "eqeeeqeeeeeqeeqeeeqqeeeeeeeeqeeeeeeeeeeeeeeqqeeqqqeeeqeeeeeeeeqeeqeeeeeq"
      "eqqeqeeqqeeeeeeeeeeqeqeqeeeeeqeeeeeeeeeqeqeeeeeeqqeeeqeeeeqeeeeeeqeeqeee"
      "eqeeeeeeeqeeqeeeeqeeqeeeeeeeeeeeqqeeeeeeeqeeeeeqeeqeeeeeeqeqeeeqeeeeeeee"
      "qeeeeeqeeeeeeeeeeqeqeeeeqqqeeeeeeqqqeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeqeeeee"
      "qeeqqeeqeeeeeeeeeeeeeeqeeqqeeeqeeeeeeeeeeeqeeeeqeeeeeeeeeeeeqeeeeeqeeeee"
      "eeeeeeqeqqeqqeeeeeeeeeeqqeeeeeeeeeqeeeeeeeeeeeeeeeeeeeqeeqqeeqeeeeeeqeeq"
      "eeeqeeeeeeqeeeeqeeqeqqqeeeqeeeeeeeeqqeeqeeeeqeeeeqeeeeeeeeeqqeeqqeeeeeeq"
      "eeeeeeeeqqeeeeeeeqeeeeeeeeeeeeqeeqeeeeeeeeeqeqeeqeeeeeeeeeeqeeqeeeeeeqee"
      "eqeeeeeeeeeqqeeqqeeeeeqeeeqeeeeeeeeeeeeeeeeqeqeeeeeeqeeqeeeqeeeqeeqeeqee"
      "eeeeqqeeeeeeeeeqqqeqqeeeqeeeeqqeeqqqeeeqeeeeqeeeeeeeeqeeeeqqqeeeeqeeeeqe"
      "qqeeqeeeeeeeeeeqeeeeeqqqeeqeeeeeeeeeeeqeeeeqeeeeeeeeeeqeeeqeeqeeeeeeqqeq"
      "eqqeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeqqeeeeeeeeeeeeeqqeqeqeeeeeeqeeeeqqqeeeq"
      "qeqqeeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeqeqeeeeeeeeeeeeeeeeeqqqeeqeeeeqeee"
      "eeqqeeeeeeeqeeeeeqqeeqqqqeeeeeeeeeeeqeeeeeeeeeeqeeqeeqeeeeeeeeeeeeqeqeeq"
      "eeeeeqqeeeeqqeeeqqeeeeeeeeeeqeeeqqeeeqeeeeeeqeeqqeeeqeqqeeeqeqeqqeeeqeee"
      "eeeeqeeeqeeeeeeqqeeqeeqeeeeeqeeeeqeeqeeqeqeeeeeeqeeeeqeeqeeeeeqeeqeqeeee"
      "eeqeeeeeeeeeeeeeeqeeqeeqeeeeeeeqeeqeeeeeeeqeeeeeeeeeeeeeqqeeeeeeqeeeeqee"
      "qeqeeeeeeeeqeqeqeeeeeeeqeqeeeeeeeeqeeeqeeeeeeeeeeeeeeqeeqeeeeeeeqeeeeeee"
      "eeeeqqeeeqeqqeeeeeeeqeeeeeqeeqeeeeqeeqeeeqeeeeeqqeeqeeeqeeeeeqeeeeeqeqee"
      "qqeeeeqeeeeeeeeeeeeeeeeeqeqeeeeqeeqeqeqeeeeeeeeqeeeeeqqeeeqeeeeqqeeeeeeq"
      "eeeeeeqeeeqeeeeeeeeeeqqeeeeeeeeqeeeqeeqeeeeeeqeeqeeeeeeeeqeqeeeeeeeeeeqe"
      "eeeeeeeqeqeqqeeeqeeeeqeeeeeeqeeeeqeeeqeeeeeeeeqeqqqqeqeeeeeqeeeqeeeeeeeq"
      "eqeeqeeeqeeeqeeeqeeeeeeqqqeqeeqeeeeeeqeqeqeeeeeeeeeqeqeeqeeqeeeeeeeeeqee"
      "eeeeeeeeeeeeeeeeeeeeqqqeeeeeeqeqeqeeqqeeeqqeeeqeeeeeqeeqeqeeqeeeeeeeeqee"
      "eqeeeeeeeqeeeeeqeqeqeqeqeeeeeeeeqeeeeqqqqeeeeqeeeeeeeeeeqeeqeeeqeeeqeeee"
      "qeeeeeeqqqqeeqeeqeeeeeeqqeeeeeeeeeqeqqeeeeeeqeeeeeqeqeeqqeeqqeeeeeeeqqqe"
      "eeeeeeeeqeeeeeqeqeeeeeeeqqqqqeeqeeqeeeeqeeeeeqeeeeeeeeqeqeeeeeeeeeeqeeqe"
      "eeeeeeeeeeeqqeeeqqeeeeeeeeeeqeqeeeqeeeeeeeqeeeeeeeeeeeeeeeqeeeeeeqqeeqeq"
      "eeeeeeeqeqeqqeeeqeeeqeeeqeeeeeqqeeeeeeqeeqqeeeeeeeeqeeeeeqeeeeeeeeeeeeee"
      "eqeeeeqqeeeeeqeeqeeeeqqeeeeeeeqeeeeqqeeeqeqeqeeeeeqeeeeeeqeqeeeeqeeeeqee"
      "eeqeeqeeeeqqeeeeeeeqeeeeeeeeeqeqeeeeeeeeeqeqeeeeeqeqeqqeqeqeeeqeeeqeqeqq"
      "qqqeeqeeeeqeeeqeeeqeeqeeeqeeeeeeqqeeeqeeeeeeeeeeeeeeqeqeeqeeeeqeeqeeeqqe"
      "eeeeeeeeeeeeqeeqeeeeeeeeeqeeeqqeeeeeeeeeeqeeeeeqeeeeeeeqeeeeeeeeeeeeeeee"
      "qeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeqeeee"
      "eeeqeeeeeeeeeeeeqeeeeeeeeeeeeeeeqeeeeeeeqeqeeeeeeeeeqeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeeqqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
      "eeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeq"
      "eeeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeqeeeeeeeeeeeeeeqeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
      "eeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeqeqeeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeqee"
      "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
      "eeqeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
      "eeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeqeeeeeeeeeeeeeeeeeeeeeeeeeqeeeeeeeeeeee"
      "eeeeeeeeeee";
  EXPECT_EQ(sol.largestMerge(s1, s2), expect);
}
