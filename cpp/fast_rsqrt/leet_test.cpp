#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

vector<float> rs;

TEST(kk, t1) {
#if 0
  for(int i=1; i<10; i++){
  double expect = 1 / sqrt(i);
  double actual = fast_rsqrt(i);
    LOG(INFO) << "actual: " << actual << ", error: " << actual - expect;
  }
#endif  
  srand(time(NULL));
  for(int i=0; i<1000000; i++){
    int up =  1 + rand() % 100000;
    int down = 1 + rand() % 100000;
    rs.push_back(float(up) / float(down));
  }
  LOG(INFO) << "last element of rs: " << rs.back();
  LOG(INFO) << "max element of rs: " << *max_element(rs.begin(), rs.end());
  LOG(INFO) << "min element of rs: " << *min_element(rs.begin(), rs.end());
}

TEST(kk, traditional_sqrt) {
  for(int i=rs.size()-1; i>=0; i--){
    auto res = 1 / sqrt(rs[i]);
  }
}


TEST(kk, fast_rsqrt) {
  for(int i=rs.size()-1; i>=0; i--){
    auto res = fast_rsqrt(rs[i]);
  }
}



