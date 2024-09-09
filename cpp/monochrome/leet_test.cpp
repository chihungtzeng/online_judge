#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  auto monochrome = get_monochrome();
  flip(monochrome, 4*8, 3);
  for(auto val: monochrome) {
    printf("%02x\n", val);
  }
}

TEST(kk, t1_1) {
  vector<uint32_t> vals{ 0xa26302ae, 0x32b8d305, 0x49e001d5 };
  for(auto val: vals) {
    auto rev = rev_uint32(val);
    printf("rev(%x) -> %x\n", val, rev);
  }
}

TEST(kk, t2) {
  EXPECT_EQ(rev_byte_simple(0xa2), 0x45);
  EXPECT_EQ(rev_byte(0xa2), 0x45);
}


