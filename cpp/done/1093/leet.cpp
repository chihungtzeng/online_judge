#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<double> sampleStats(vector<int>& count) {
    uint64_t nsample = 0;
    uint64_t sum = 0;
    for (int i = 0; i < 256; i++) {
      nsample += count[i];
      sum += count[i] * i;
    }
    return vector<double>{find_min(count), find_max(count),
                          sum / double(nsample), find_median(count, nsample),
                          find_mode(count)};
  }
  double find_min(vector<int>& count) {
    for (int i = 0; i < 256; i++) {
      if (count[i] > 0) return i;
    }
    return 255;
  }
  double find_max(vector<int>& count) {
    for (int i = 255; i >= 0; i--) {
      if (count[i] > 0) return i;
    }
    return 0;
  }
  double find_median(vector<int>& count, uint64_t nsample) {
    if (nsample % 2 == 0) {
      int mid_left = find_nth_num(count, nsample / 2 + 1);
      int mid_right = find_nth_num(count, nsample / 2);
      return (mid_left + mid_right) / 2.0;
    } else {
      return double(find_nth_num(count, nsample / 2));
    }
  }
  double find_mode(vector<int>& count) {
    int target = -1;
    int occr = -1;
    for (int i = 0; i < 256; i++) {
      if (count[i] > occr) {
        occr = count[i];
        target = i;
      }
    }
    return target;
  }

  int find_nth_num(vector<int>& count, int idx) {
    int pos = 0;
    for (int i = 0; i < 256; i++) {
      pos += count[i];
      if (pos >= idx) return i;
    }
    return 0;
  }
};
