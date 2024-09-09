#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

/*
TEST(kk, t0) {
  Solution sol;
  EXPECT_EQ(sol.next_rotation("abc"), "bcd");
  EXPECT_EQ(sol.next_rotation("z"), "a");
  EXPECT_EQ(sol.next_rotation("xyz"), "yza");
}
*/

TEST(kk, t1) {
  Solution sol;
  vector<string> input{"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
  vector<vector<string>> expect{
      {"abc", "bcd", "xyz"}, {"az", "ba"}, {"acef"}, {"a", "z"}};

  auto output = sol.groupStrings(input);
  sort(output.begin(), output.end());
  sort(expect.begin(), expect.end());
  EXPECT_EQ(output , expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<string> input{"a", "a"};
  vector<vector<string>> expect{{"a", "a"}};

  EXPECT_EQ(sol.groupStrings(input), expect);
}

