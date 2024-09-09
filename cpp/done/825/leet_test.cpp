#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> ages{16,16};
  EXPECT_EQ(sol.numFriendRequests(ages), 2);
}

TEST(kk, t2) {
  Solution sol;

  vector<int> ages {16,17,18};
  EXPECT_EQ(sol.numFriendRequests(ages), 2);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> ages {20,30,100,110,120};

  EXPECT_EQ(sol.numFriendRequests(ages), 3);
}

TEST(kk, t3_1) {
  Solution sol;
  for(int i=1; i<=120; i++){
    vector<int> ages {i};
    EXPECT_EQ(sol.numFriendRequests(ages), 0);
  }
}



TEST(kk, t4) {
  Solution sol;
  vector<int> ages{1, 6, 64, 8, 41, 39, 64, 30, 12, 79, 11, 56, 30, 86, 53, 102, 26, 86, 71, 11, 69, 66, 36, 25, 33, 92, 80, 41, 45, 95, 92, 46, 92, 35, 45, 12, 74, 108, 41, 77, 67, 51, 4, 96, 16, 49, 69, 33, 14, 11, 44, 82, 77, 79, 98, 109, 42, 57, 22, 78, 23, 113, 3, 114, 20, 47, 117, 85, 35, 38, 41, 93, 80, 44, 60, 88, 84, 8, 120, 97, 18, 35, 58, 94, 105, 28, 75, 18, 84, 96, 96, 99, 80, 98, 84, 99, 17, 81, 63, 43, 118, 95, 15, 69, 11, 66, 36, 94, 73, 28, 71, 82, 62, 120, 48, 47, 19, 2, 56, 95, 89, 31, 73, 40, 1, 36, 19, 17, 108, 73, 51, 97, 48, 57, 46, 50, 2, 81, 15, 66, 108, 77, 27, 42, 77, 74, 80, 95, 67, 15, 69, 35, 38, 13, 75, 38, 41, 85, 46, 28, 29, 96, 5, 68, 32, 42, 117, 25, 2, 12, 90, 102, 88, 116, 15, 36, 62, 94, 3, 120, 100, 63, 27, 17, 76, 93, 46, 108, 57, 91, 7, 85, 58, 3, 25, 81, 44, 21, 105, 38};

  EXPECT_EQ(sol.numFriendRequests(ages), 7672);
}

#if 0
TEST(kk, t) {
  Solution sol;
  srand(time(NULL));
  vector<int> ages;
  for(int i=0; i<200; i++){
    ages.push_back(1 + rand() % 120);
  }
  for(int i=0; i<ages.size(); i++){
    cout << ages[i] << ", ";
  }
  cout << endl;

  EXPECT_EQ(sol.numFriendRequests(ages), 100);
}
#endif
