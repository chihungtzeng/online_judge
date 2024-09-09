#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<string> stickers = { "with", "example", "science" };
  string target = "thehat";
  EXPECT_EQ(sol.minStickers(stickers, target), 3);
}

TEST(kk, t2)
{
  Solution sol;
  vector<string> stickers = { "notice", "possible" };
  string target = "basicbasic";
  EXPECT_EQ(sol.minStickers(stickers, target), -1);
}

TEST(kk, t3)
{
  Solution sol;
  vector<string> stickers = {"control","heart","interest","stream","sentence","soil","wonder","them","month","slip","table","miss","boat","speak","figure","no","perhaps","twenty","throw","rich","capital","save","method","store","meant","life","oil","string","song","food","am","who","fat","if","put","path","come","grow","box","great","word","object","stead","common","fresh","the","operate","where","road","mean"};
  string target = "stoodcrease";
  EXPECT_EQ(sol.minStickers(stickers, target), 3);
}




