#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  SnapshotArray snapshotArr(3);
  snapshotArr.set(0, 5);                             // Set array[0] = 5
  EXPECT_EQ(snapshotArr.snap(), 0);
  snapshotArr.set(0, 6);
  EXPECT_EQ(snapshotArr.get(0, 0), 5);
  EXPECT_EQ(snapshotArr.snap(), 1);

  snapshotArr.set(1, 2);
  snapshotArr.set(1, 33);
  snapshotArr.set(0, 16);
  EXPECT_EQ(snapshotArr.snap(), 2);
  EXPECT_EQ(snapshotArr.get(0, 0), 5);
  EXPECT_EQ(snapshotArr.get(0, 1), 6);
  EXPECT_EQ(snapshotArr.get(0, 2), 16);
  snapshotArr.set(1, 37);
  EXPECT_EQ(snapshotArr.get(1, 2), 33);
}

TEST(kk, t2) {
  SnapshotArray snapshotArr(1);
  snapshotArr.set(0, 15);
  EXPECT_EQ(snapshotArr.snap(), 0);
  EXPECT_EQ(snapshotArr.snap(), 1);
  EXPECT_EQ(snapshotArr.snap(), 2);
  EXPECT_EQ(snapshotArr.get(0, 2), 15);
  EXPECT_EQ(snapshotArr.snap(), 3);
  EXPECT_EQ(snapshotArr.snap(), 4);
  EXPECT_EQ(snapshotArr.get(0, 0), 15);
}

TEST(kk, t3) {
  SnapshotArray snapshotArr(2);
  EXPECT_EQ(snapshotArr.snap(), 0);
  EXPECT_EQ(snapshotArr.get(1, 0), 0);
  EXPECT_EQ(snapshotArr.get(0, 0), 0);
  snapshotArr.set(1, 8);
  EXPECT_EQ(snapshotArr.get(1, 0), 0);
  snapshotArr.set(0, 20);
  EXPECT_EQ(snapshotArr.get(0, 0), 0);
  snapshotArr.set(0, 7);
}

