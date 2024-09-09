#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<char>> seats = {{'#', '.', '#', '#', '.', '#'},
                                {'.', '#', '#', '#', '#', '.'},
                                {'#', '.', '#', '#', '.', '#'}};
  EXPECT_EQ(sol.maxStudents(seats), 4);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<char>> seats = {
      {'.', '#'}, {'#', '#'}, {'#', '.'}, {'#', '#'}, {'.', '#'}};
  EXPECT_EQ(sol.maxStudents(seats), 3);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<char>> seats = {{'#', '.', '.', '.', '#'},
                                {'.', '#', '.', '#', '.'},
                                {'.', '.', '#', '.', '.'},
                                {'.', '#', '.', '#', '.'},
                                {'#', '.', '.', '.', '#'}};
  EXPECT_EQ(sol.maxStudents(seats), 10);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<char>> seats = {{'.', '.', '.', '.', '.', '.', '.', '.'},
                                {'.', '.', '.', '.', '.', '.', '.', '.'},
                                {'.', '.', '.', '.', '.', '.', '.', '.'},
                                {'.', '.', '.', '.', '.', '.', '.', '.'},
                                {'.', '.', '.', '.', '.', '.', '.', '.'},
                                {'.', '.', '.', '.', '.', '.', '.', '.'},
                                {'.', '.', '.', '.', '.', '.', '.', '.'},
                                {'.', '.', '.', '.', '.', '.', '.', '.'}};
  EXPECT_EQ(sol.maxStudents(seats), 32);
}

TEST(kk, t5){
  vector<int> pi{3,4,1,5,9,2,6};
  set<int> m;
  for(auto v: pi){
    m.insert(v);
  }
  sort(pi.begin(), pi.end());
  // LOG(INFO) << dst - src;
  for(int i=0; i<pi.size(); i++){
    for(int j=i+1; j<pi.size(); j++){
      if (pi[i] == pi[j]) continue;
      auto src = m.find(pi[i]);
      auto dst = m.find(pi[j]);
      EXPECT_EQ(distance(src, dst), j -i);
    }
  }

}

