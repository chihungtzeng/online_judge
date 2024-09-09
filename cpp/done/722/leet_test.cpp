#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> source = {"/*Test program */",
                           "int main()",
                           "{ ",
                           "  // variable declaration ",
                           "int a, b, c;",
                           "/* This is a test",
                           "   multiline  ",
                           "   comment for ",
                           "   testing */",
                           "a = b + c;",
                           "}"};
  vector<string> expect{"int main()",   "{ ",         "  ",
                        "int a, b, c;", "a = b + c;", "}"};

  EXPECT_EQ(sol.removeComments(source), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<string> source = {"a/*comment", "line", "more_comment*/b"};
  vector<string> expect{"ab"};

  EXPECT_EQ(sol.removeComments(source), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<string> source = {"struct Node{", "    /*/ declare members;/**/", "    int size;", "    /**/int val;", "};"};
  vector<string> expect{"struct Node{","    ","    int size;","    int val;","};"};
  EXPECT_EQ(sol.removeComments(source), expect);
}

