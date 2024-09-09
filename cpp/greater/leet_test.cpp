#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  EXPECT_EQ(greater<>()(5, 3), true);
  EXPECT_EQ(greater<>()(5, 5), false);
  EXPECT_EQ(greater<>()(3.1, 5.2), false);
}

TEST(kk, t2) {
  auto obj = greater<>();
  LOG(INFO) << "greater<>() size: " << sizeof(obj);
}

TEST(kk, t3){
  std::function<bool(int, int)> less = [](int a, int b) {return a < b;};
  EXPECT_EQ(less(3, 5), true);
  EXPECT_EQ(less(3, 3), false);
  EXPECT_EQ(less(5, 3), false);
}

