#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  UndergroundSystem undergroundSystem;
  undergroundSystem.checkIn(45, "Leyton", 3);
  undergroundSystem.checkIn(32, "Paradise", 8);
  undergroundSystem.checkIn(27, "Leyton", 10);
  undergroundSystem.checkOut(45, "Waterloo", 15);
  undergroundSystem.checkOut(27, "Waterloo", 20);
  undergroundSystem.checkOut(32, "Cambridge", 22);
  EXPECT_EQ(undergroundSystem.getAverageTime("Paradise", "Cambridge"), 14.0);
  EXPECT_EQ(undergroundSystem.getAverageTime("Leyton", "Waterloo"), 11.0);
  undergroundSystem.checkIn(10, "Leyton", 24);
  EXPECT_EQ(undergroundSystem.getAverageTime("Leyton", "Waterloo"), 11.0);
  undergroundSystem.checkOut(10, "Waterloo", 38);
  EXPECT_EQ(undergroundSystem.getAverageTime("Leyton", "Waterloo"), 12.0);
  //delete undergroundSystem;
}

TEST(kk, t2) {
  UndergroundSystem undergroundSystem;
  undergroundSystem.checkIn(10, "Leyton", 3);
  undergroundSystem.checkOut(10, "Paradise", 8);
  EXPECT_EQ(undergroundSystem.getAverageTime("Leyton", "Paradise"), 5.0);
  undergroundSystem.checkIn(5, "Leyton", 10);
  undergroundSystem.checkOut(5, "Paradise", 16);
  EXPECT_EQ(undergroundSystem.getAverageTime("Leyton", "Paradise"), 5.5);
  undergroundSystem.checkIn(2, "Leyton", 21);
  undergroundSystem.checkOut(2, "Paradise", 30);
  EXPECT_TRUE(abs(undergroundSystem.getAverageTime("Leyton", "Paradise") - 6.66667) <= 1e-5);

  //delete undergroundSystem;
}
