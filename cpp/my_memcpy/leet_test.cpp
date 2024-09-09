#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

const size_t n = 10000000;

TEST(kk, t1) {
  int32_t *src = new int[n];
  for(int i=0; i<n; i++){
    src[i] = i;
  }
  int32_t *dest = new int[n];

  mymemcpy(dest, src, n * sizeof(int));

  for(int i=0; i<n; i++){
    EXPECT_EQ(dest[i], i);
  }

  delete [] dest;
  delete [] src;
}

TEST(kk, t2) {
  int32_t *src = new int[n];
  for(int i=0; i<n; i++){
    src[i] = i;
  }
  int32_t *dest = new int[n];

  mymemcpy64(dest, src, n * sizeof(int));

  for(int i=0; i<n; i++){
    EXPECT_EQ(dest[i], i);
  }

  delete [] dest;
  delete [] src;
}

