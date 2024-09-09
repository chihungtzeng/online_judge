#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  RangeModule* obj = new RangeModule();
  obj->addRange(10, 20);
  obj->removeRange(14, 16);
  EXPECT_EQ(obj->queryRange(10, 14), true);
  EXPECT_EQ(obj->queryRange(13, 15), false);
  EXPECT_EQ(obj->queryRange(16, 17), true);
  delete obj;
}

TEST(kk, t2) {
  RangeModule* obj = new RangeModule();
  obj->addRange(10, 20);
  obj->addRange(50, 60);
  obj->addRange(90, 100);
  obj->addRange(30, 40);
  obj->addRange(35, 45);
  obj->removeRange(14, 16);
  EXPECT_EQ(obj->queryRange(10, 14), true);
  EXPECT_EQ(obj->queryRange(13, 15), false);
  EXPECT_EQ(obj->queryRange(16, 17), true);
  obj->removeRange(35, 55);
  delete obj;
}

TEST(kk, t3) {
  RangeModule* obj = new RangeModule();
  obj->addRange(10, 180);
  obj->addRange(150, 200);
  obj->addRange(250, 500);
  EXPECT_EQ(obj->queryRange(50, 100), true);
  EXPECT_EQ(obj->queryRange(180, 300), false);
  EXPECT_EQ(obj->queryRange(600, 1000), false);
  obj->removeRange(50, 150);
  EXPECT_EQ(obj->queryRange(50, 100), false);
  delete obj;
}

TEST(kk, t4) {
  RangeModule* obj = new RangeModule();
  obj->addRange(6, 8);
  obj->removeRange(7, 8);
  obj->removeRange(8, 9);
  obj->addRange(8,9);
  obj->removeRange(1, 3);
  obj->addRange(1, 8);
  EXPECT_EQ(obj->queryRange(2, 4), true);
  EXPECT_EQ(obj->queryRange(2, 9), true);
  EXPECT_EQ(obj->queryRange(4, 6), true);
  delete obj;
}

TEST(kk, t5) {
  RangeModule* obj = new RangeModule();
  obj->addRange(5, 8);
  EXPECT_EQ(obj->queryRange(3, 4), false);
  obj->removeRange(5, 6);
  obj->removeRange(3, 6);
  obj->addRange(1,3);
  EXPECT_EQ(obj->queryRange(2, 3), true);
  obj->addRange(4, 8);
  EXPECT_EQ(obj->queryRange(2, 3), true);
  obj->removeRange(4,9);
  delete obj;
}


TEST(kk, t6) {
  RangeModule* obj = new RangeModule();
  EXPECT_EQ(obj->queryRange(21,34), false);
  EXPECT_EQ(obj->queryRange(27,87), false);
  obj->addRange(44,53);
  obj->addRange(69,89);
  EXPECT_EQ(obj->queryRange(23,26), false);
  EXPECT_EQ(obj->queryRange(80,84), true);
  EXPECT_EQ(obj->queryRange(11,12), false);
  obj->removeRange(86,91);
  obj->addRange(87,94);
  obj->removeRange(34,52);
  obj->addRange(1,59);
  obj->removeRange(62,96);
  obj->removeRange(34,83);
  EXPECT_EQ(obj->queryRange(11,59), false);
  EXPECT_EQ(obj->queryRange(59,79), false);
  EXPECT_EQ(obj->queryRange(1,13), true);
  EXPECT_EQ(obj->queryRange(21,23), true);
  obj->removeRange(9,61);
  obj->addRange(17,21);
  obj->removeRange(4,8);
  EXPECT_EQ(obj->queryRange(19,25), false);
  obj->addRange(71,98);
  obj->addRange(23,94);
  obj->removeRange(58,95);
  EXPECT_EQ(obj->queryRange(12,78), false);
  obj->removeRange(46,47);
  obj->removeRange(50,70);
  obj->removeRange(84,91);
  obj->addRange(51,63);
  obj->removeRange(26,64);
  obj->addRange(38,87);
  EXPECT_EQ(obj->queryRange(41,84), true);
  EXPECT_EQ(obj->queryRange(19,21), true);
  EXPECT_EQ(obj->queryRange(18,56), false);
  EXPECT_EQ(obj->queryRange(23,39), false);
  EXPECT_EQ(obj->queryRange(29,95), false);
  obj->addRange(79,100);
  obj->removeRange(76,82);
  obj->addRange(37,55);
  obj->addRange(30,97);
  obj->addRange(1,36);
  EXPECT_EQ(obj->queryRange(18,96), true);
  obj->removeRange(45,86);
  obj->addRange(74,92);
  EXPECT_EQ(obj->queryRange(27,78), false);
  obj->addRange(31,35);
  EXPECT_EQ(obj->queryRange(87,91), true);
  obj->removeRange(37,84);
  obj->removeRange(26,57);
  obj->addRange(65,87);
  obj->addRange(76,91);
  EXPECT_EQ(obj->queryRange(37,77), false);
  EXPECT_EQ(obj->queryRange(18,66), false);
  obj->addRange(22,97);
  obj->addRange(2,91);
  obj->removeRange(82,98);
  obj->removeRange(41,46);
  obj->removeRange(6,78);
  EXPECT_EQ(obj->queryRange(44,80), false);
  obj->removeRange(90,94);
  obj->removeRange(37,88);
  obj->addRange(75,90);
  EXPECT_EQ(obj->queryRange(23,37), false);
  obj->removeRange(18,80);
  obj->addRange(92,93);
  obj->addRange(3,80);
  EXPECT_EQ(obj->queryRange(68,86), true);
  obj->removeRange(68,92);
  EXPECT_EQ(obj->queryRange(52,91), false);
  obj->addRange(43,53);
  obj->addRange(36,37);
  obj->addRange(60,74);
  obj->addRange(4,9);
  obj->addRange(44,80);
  obj->removeRange(85,93);
  obj->removeRange(56,83);
  obj->addRange(9,26);
  EXPECT_EQ(obj->queryRange(59,64), false);
  EXPECT_EQ(obj->queryRange(16,66), false);
  obj->removeRange(29,36);
  obj->removeRange(51,96);
  obj->removeRange(56,80);
  obj->addRange(13,87);
  EXPECT_EQ(obj->queryRange(42,72), true);
  obj->removeRange(6,56);
  EXPECT_EQ(obj->queryRange(24,53), false);
  obj->addRange(43,71);
  obj->removeRange(36,83);
  obj->removeRange(15,45);
  EXPECT_EQ(obj->queryRange(10,48), false);
  delete obj;
}



