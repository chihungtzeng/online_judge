#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  SummaryRanges* obj = new SummaryRanges();
  obj->addNum(1);
  std::vector<std::vector<int>> expect{{1,1}};
  EXPECT_EQ(obj->getIntervals(), expect);

  obj->addNum(3);
  std::vector<std::vector<int>> expect2{{1,1}, {3,3}};
  EXPECT_EQ(obj->getIntervals(), expect2);

  obj->addNum(7);
  std::vector<std::vector<int>> expect3{{1,1}, {3,3}, {7,7}};
  EXPECT_EQ(obj->getIntervals(), expect3);

  obj->addNum(2);
  std::vector<std::vector<int>> expect4{{1,3}, {7,7}};
  EXPECT_EQ(obj->getIntervals(), expect4);

  obj->addNum(6);
  std::vector<std::vector<int>> expect5{{1,3}, {6,7}};
  EXPECT_EQ(obj->getIntervals(), expect5);
  delete obj;
}

TEST(kk, t2) {
  SummaryRanges* obj = new SummaryRanges();
  obj->addNum(6);
  obj->addNum(6);
  obj->addNum(0);
  obj->addNum(4);
  obj->addNum(8);
  obj->addNum(7);
  obj->addNum(6);
  obj->addNum(4);
  obj->addNum(7);
  obj->addNum(5);

/*
  ["SummaryRanges","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals"]
  [[],[6],[],[6],[],[0],[],[4],[],[8],[],[7],[],[6],[],[4],[],[7],[],[5],[]]
*/
  std::vector<std::vector<int>> expect{{0,0}, {4,8}};
  EXPECT_EQ(obj->getIntervals(), expect);

  delete obj;
}

