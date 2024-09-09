#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  string ring = "godding", key = "gd";
  EXPECT_EQ(sol.findRotateSteps(ring, key), 4);
}

TEST(kk, t2)
{
  Solution sol;
  string ring = "godding", key = "godding";
  EXPECT_EQ(sol.findRotateSteps(ring, key), 13);
}

#if 1
TEST(kk, t3)
{
  Solution sol;
  string ring = "amazongoogleleetcodeabcdefghijklmnopqrstuvwxyz";
  string key = "weneedtorotatetheringgoddinganticlockwisebytwostepstomakeitbecomeddinggo";
  EXPECT_EQ(sol.findRotateSteps(ring, key), 556);
}
#endif
