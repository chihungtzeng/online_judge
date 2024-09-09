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

float fast_rsqrt(float number)
{
  int32_t i;
  float x2, y;
  const float threehalfs = 1.5F;

  x2 = number * 0.5F;
  y = number;
  i = *(int32_t *)&y;
  i = 0x5f3759df - (i >> 1);
  y = *(float *) &i;
  y = y * (threehalfs - x2 *y *y);
  return y;
}
