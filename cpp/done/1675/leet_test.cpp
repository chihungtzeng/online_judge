#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {1, 2, 3, 4};
  EXPECT_EQ(sol.minimumDeviation(nums), 1);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {4, 1, 5, 20, 3};
  EXPECT_EQ(sol.minimumDeviation(nums), 3);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {2, 10, 8};
  EXPECT_EQ(sol.minimumDeviation(nums), 3);
}

TEST(kk, t4) {
  Solution sol;

  vector<int> nums = {
      4585565, 256955,  5842387, 2934888, 6263749, 698870,  7203524, 4423711,
      1930512, 5602694, 5823094, 1458357, 982294,  1901316, 5979623, 3486810,
      7264682, 9329460, 5315868, 9770096, 166946,  8275938, 6670802, 7170271,
      4611817, 4947140, 6084031, 4226339, 5036467, 2528821, 5034432, 174740,
      2250959, 8696574, 4845195, 6493813, 2695150, 8103188, 8170788, 6380246,
      3034486, 5707304, 3248351, 4500505, 9502674, 5381080, 5623844, 1368277,
      8849624, 4647624, 5015814, 3163944, 7807811, 6401499, 350868,  6892709,
      4381043, 6361629, 4864437, 3621523, 1170688, 2377463, 7528299, 9916989,
      9882352, 3633475, 1988140, 8960315, 3019034, 2070311, 5531695, 5125406,
      9205137, 7444257, 6950,    6873989, 672304,  4942511, 8744151, 1767217,
      3460201, 9159990, 4118828, 3703579, 9348789, 7003686, 9435651, 1659848,
      329541,  4050260, 9492464, 2792327, 9896136, 8913211, 4378687, 1862679,
      4357115, 7263721, 8703714, 394106};
  EXPECT_EQ(sol.minimumDeviation(nums), 9910039);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> nums = {3,5};
  EXPECT_EQ(sol.minimumDeviation(nums), 1);
}

TEST(kk, t6) {
  Solution sol;
  vector<int> nums = {2,4,8,16};
  EXPECT_EQ(sol.minimumDeviation(nums), 0);
}


