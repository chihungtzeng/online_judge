#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.checkValidString("()"), true);
  EXPECT_EQ(sol.checkValidString("(*)"), true);
  EXPECT_EQ(sol.checkValidString("(*))"), true);
  EXPECT_EQ(sol.checkValidString("()*)"), true);
  EXPECT_EQ(sol.checkValidString("()*)***"), true);
  EXPECT_EQ(sol.checkValidString("()*))"), false);
  EXPECT_EQ(sol.checkValidString("*("), false);
  EXPECT_EQ(sol.checkValidString("(())((())()()(*)(*()(())())())()()((()())((()))(*"), false);

}

