#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> folder = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
  vector<string> expect{"/a", "/c/d", "/c/f"};
  EXPECT_EQ(sol.removeSubfolders(folder), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<string> folder = {"/a", "/a/b/c", "/a/b/d"};
  vector<string> expect{"/a"};
  EXPECT_EQ(sol.removeSubfolders(folder), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<string> folder = {"/a/b/c", "/a/b/ca", "/a/b/d"};
  vector<string> expect{"/a/b/c", "/a/b/ca", "/a/b/d"};
  sort(expect.begin(), expect.end());
  auto actual = sol.removeSubfolders(folder);
  sort(actual.begin(), actual.end());
  EXPECT_EQ(actual, expect);
}

