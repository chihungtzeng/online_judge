#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;

  vector<char> input{'t', 'h', 'e', ' ', 's', 'k', 'y', ' ',
                     'i', 's', ' ', 'b', 'l', 'u', 'e'};
  vector<char> output{'b', 'l', 'u', 'e', ' ', 'i', 's', ' ',
                      's', 'k', 'y', ' ', 't', 'h', 'e'};
  sol.reverseWords(input);
  EXPECT_EQ(input, output);
}

