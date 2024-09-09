#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <queue>
using namespace std;

void mymemcpy(void *dest, const void* src, size_t n)
{
  uint8_t *to = (uint8_t *) dest;
  uint8_t *ptr = (uint8_t *) src;
  for(size_t i=0; i<n; i++){
    *to = *ptr;
    to++;
    ptr++;
  }
}

void mymemcpy64(void *dest, const void* src, size_t nbytes)
{
  uint64_t *to64 = (uint64_t *) dest;
  uint64_t *ptr64 = (uint64_t *) src;
  while (nbytes >= 8)
  {
    *to64++ = *ptr64++;
    nbytes -= 8;
  }
  uint8_t *to8 = (uint8_t *) to64;
  uint8_t *ptr8 = (uint8_t *) ptr64;
  while (nbytes > 0) {
    *to8++ = *ptr8++;
    nbytes--;
  }
}
