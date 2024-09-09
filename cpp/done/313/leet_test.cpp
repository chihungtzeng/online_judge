#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> primes{2,7,13,19};

  EXPECT_EQ(sol.nthSuperUglyNumber(12, primes), 32);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> primes{7,19,29,37,41,47,53,59,61,79,83,89,101,103,109,127,131,137,139,157,167,179,181,199,211,229,233,239,241,251};

  EXPECT_EQ(sol.nthSuperUglyNumber(100000, primes), 1092889481);
}

