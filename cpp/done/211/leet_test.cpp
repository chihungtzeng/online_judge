#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  WordDictionary* wd = new WordDictionary();
  wd->addWord("bad");
  wd->addWord("dad");
  wd->addWord("mad");
  EXPECT_FALSE(wd->search("pad"));  // return False
  EXPECT_TRUE(wd->search("bad"));  // return True
  EXPECT_TRUE(wd->search(".ad"));  // return True
  EXPECT_TRUE(wd->search("b.."));  // return True
  delete wd;
}

