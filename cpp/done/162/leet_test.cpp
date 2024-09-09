#include <gtest/gtest.h>
#include "leet.cpp"

TEST(kerker, t1)
{
  Solution sol;
  std::vector<int> nums{1,2,3,1};
  int expect = 2;
  EXPECT_EQ(expect, sol.findPeakElement(nums));
}

TEST(kerker, t2)
{
  Solution sol;
  std::vector<int> nums{1,2,1,3,5,6,4};
  auto actual = sol.findPeakElement(nums);
  EXPECT_TRUE(actual == 1 or actual == 5);
}

TEST(kerker, t3)
{
  Solution sol;
  std::vector<int> nums{0,1,2,3,4,5,6,7};
  auto actual = sol.findPeakElement(nums);
  auto expect = 7;
  EXPECT_EQ(expect, actual);
}

TEST(kerker, t3_1)
{
  Solution sol;
  std::vector<int> nums{7,6,5,4,3,2,1,0};
  auto actual = sol.findPeakElement(nums);
  auto expect = 0;
  EXPECT_EQ(expect, actual);
}


TEST(kerker, t4)
{
  Solution sol;
  std::vector<int> nums{4,3,2,1,0};
  auto actual = sol.findPeakElement(nums);
  EXPECT_TRUE(actual == 0);
}
TEST(kerker, t5)
{
  Solution sol;
  std::vector<int> nums{4,3};
  auto actual = sol.findPeakElement(nums);
  EXPECT_TRUE(actual == 0);
}
TEST(kerker, t6)
{
  Solution sol;
  std::vector<int> nums{3,4};
  auto actual = sol.findPeakElement(nums);
  EXPECT_TRUE(actual == 1);
}
TEST(kerker, t7)
{
  Solution sol;
  std::vector<int> nums{1};
  auto actual = sol.findPeakElement(nums);
  EXPECT_TRUE(actual == 0);
}
TEST(kerker, t8)
{
  Solution sol;
  std::vector<int> nums;
  auto actual = sol.findPeakElement(nums);
  EXPECT_TRUE(actual == 0);
}
