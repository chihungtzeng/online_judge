#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
 Solution* obj = new Solution(1, 0, 0);

  for(int i=0; i<100; i++){
    vector<double> p = obj->randPoint();
    LOG(INFO) << p[0] << ' ' << p[1];
    EXPECT_TRUE(p[0]*p[0] + p[1]*p[1] <= 1);
  }

  delete obj;
}

TEST(kk, t2) {
 Solution* obj = new Solution(10,5,-7.5);

  for(int i=0; i<100; i++){
    vector<double> p = obj->randPoint();
    LOG(INFO) << p[0] << ' ' << p[1];
    EXPECT_TRUE((p[0] - 5)*(p[0]-5) + (p[1]+7.5)*(p[1]+7.5) <= 100);
  }

  delete obj;
}

TEST(kk, t3) {
  double r=0.01, xc= -73839.1, yc=-3289891.3;
 Solution* obj = new Solution(r,xc,yc);

  for(int i=0; i<100; i++){
    vector<double> p = obj->randPoint();
//    LOG(INFO) << p[0] << ' ' << p[1];
    EXPECT_TRUE((p[0] - xc)*(p[0]-xc) + (p[1]-yc)*(p[1]-yc) <= r*r);
  }

  LOG(INFO) << M_PI;
  delete obj;
}

