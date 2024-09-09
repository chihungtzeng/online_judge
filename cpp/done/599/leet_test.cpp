#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<string> list1 = { "Shogun", "Tapioca Express", "Burger King", "KFC" },
                 list2 = { "Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun" };
  vector<string> expect{ "Shogun" };
  EXPECT_EQ(sol.findRestaurant(list1, list2), expect);
}

TEST(kk, t2)
{
  Solution sol;
  vector<string> list1 = { "Shogun", "Tapioca Express", "Burger King", "KFC" },
                 list2 = { "KFC", "Shogun", "Burger King" };
  vector<string> expect{ "Shogun" };
  EXPECT_EQ(sol.findRestaurant(list1, list2), expect);
}

