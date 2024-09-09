#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
  EXPECT_EQ(sol.lengthLongestPath(input), 20);
}

TEST(kk, t2) {
  Solution sol;
  string input =
      "dir\n\tsubdir1\n\t\tfile1."
      "ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
  EXPECT_EQ(sol.lengthLongestPath(input), 32);
}

TEST(kk, t3) {
  Solution sol;
  string input = "a";
  EXPECT_EQ(sol.lengthLongestPath(input), 0);
}

TEST(kk, t4) {
  Solution sol;
  string input = "file1.txt\nfile2.txt\nlongfile.txt";
  EXPECT_EQ(sol.lengthLongestPath(input), 12);
}

