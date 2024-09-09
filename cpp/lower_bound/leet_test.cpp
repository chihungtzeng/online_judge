#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  vector<int> pi{3,1,4,1,5,9,2,6,2,7,1,8,2,8, 100, 107, 109, 102};
  sort(pi.begin(), pi.end());
  LOG(INFO) << pi << " size:" << pi.size();
  int start = 13;
  int end = 17;
  LOG(INFO) << "pi.begin() + 13 : " << *(pi.begin() + start);
  for(int d=0; d<=3; d++){
    LOG(INFO) << end-d << " : " << *(pi.begin() + end - d);
    LOG(INFO) << end-d << " : " << *lower_bound(pi.begin() + start, pi.begin() + end - d, 108);
    LOG(INFO) << end-d << " : " << binary_search(pi.begin() + start, pi.begin() + end - d, 107);
  }
}

TEST(kk, t2)
{
  //               0,1,2,3 ,4 ,5 ,6 ,7 ,8
  vector<int> vals{1,5,9,10,11,12,13,13,15};
  for (auto target: vector<int>{13, 14, 15, 16}) {
    auto it = lower_bound(vals.begin(), vals.end(), target);
    int idx = it - vals.begin();
    LOG(INFO) << "lower bound of " << target << " : " << idx;
  }
}
