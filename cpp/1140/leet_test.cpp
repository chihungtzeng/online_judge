#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> piles = {2, 7, 9, 4, 4};
  EXPECT_EQ(sol.stoneGameII(piles), 10);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> piles = {1, 2, 3, 4, 5, 100};
  EXPECT_EQ(sol.stoneGameII(piles), 104);
}

TEST(kk, t2_1) {
  Solution sol;
  vector<int> piles = {1};
  EXPECT_EQ(sol.stoneGameII(piles), 1);
}


TEST(kk, t3) {
  Solution sol;
  vector<int> piles = {
      476, 832, 65,  143, 432, 1,   410, 843, 835, 874, 487, 370, 261, 952, 727,
      452, 625, 230, 36,  288, 103, 423, 123, 546, 921, 62,  376, 259, 916, 44,
      580, 966, 161, 645, 698, 442, 562, 229, 437, 90,  921, 838, 258, 807, 136,
      387, 412, 227, 398, 636, 753, 523, 981, 701, 294, 877, 121, 947, 420, 666,
      185, 434, 711, 195, 615, 862, 643, 14,  578, 505, 14,  463, 298, 50,  89,
      441, 211, 968, 100, 464, 877, 882, 42,  418, 892, 624, 786, 173, 331, 559,
      251, 365, 920, 634, 80,  386, 802, 708, 596, 612};
  EXPECT_EQ(sol.stoneGameII(piles), 24381);
}

