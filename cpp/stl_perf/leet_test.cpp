#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

constexpr int ub = 10000;

TEST(kk, list_bsearch_by_stl_lower_bound) {
  Solution sol;
  list<int> nums;
  for(int i=0; i<ub; i++){
    nums.push_back(i);
  }


  for(int i=0; i<ub; i++){
    EXPECT_EQ(sol.bsearch(nums, i), i);
  }
}

TEST(kk, vector_bsearch_by_stl_lower_bound) {
  Solution sol;
  vector<int> nums;
  for(int i=0; i<ub; i++){
    nums.push_back(i);
  }

  for(int i=0; i<ub; i++){
    EXPECT_EQ(sol.bsearch(nums, i), i);
  }
}

TEST(kk, vector_bsearch_by_stl_advance) {
  Solution sol;
  list<int> nums;
  for(int i=0; i<ub; i++){
    nums.push_back(i);
  }

  for(int i=0; i<ub; i++){
    EXPECT_EQ(sol.bsearch2(nums, i), i);
  }
}

TEST(kk, set_lower_bound) {
  Solution sol;
  set<int> nums;
  for(int i=0; i<ub; i++){
    nums.insert(i);
  }

  for(int i=0; i<ub; i++){
    EXPECT_EQ(sol.lower_bound(nums, i), i);
  }
}


TEST(kk, set_iterator_next) {
  Solution sol;
  set<int> nums;
  for(int i=0; i<ub; i++){
    nums.insert(i);
  }

  for(int i=0; i<ub; i++){
    EXPECT_EQ(sol._next(nums, i), i);
  }
}

TEST(kk, set_iterator_advance) {
  Solution sol;
  set<int> nums;
  for(int i=0; i<ub; i++){
    nums.insert(i);
  }

  for(int i=0; i<ub; i++){
    EXPECT_EQ(sol._advance(nums, i), i);
  }
}

