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
  vector<int> circularPermutation(int n, int start) {
    if (n == 1) {
      if (start == 0)
        return {0, 1};
      else
        return {1, 0};
    }
    vector<int> gray{0, 1};
    for (int i = 2; i <= n; i++) {
      int k = gray.size() - 1;
      int msb = 1 << (i - 1);
      while (k >= 0) {
        gray.push_back(gray[k] | msb);
        k--;
      }
    }
    int pos = -1;
    for (int i = gray.size() - 1; i >= 0 && pos < 0; i--) {
      if (gray[i] == start) pos = i;
    }
    vector<int> ret{gray.begin() + pos, gray.end()};
    for (int i = 0; i < pos; i++) {
      ret.push_back(gray[i]);
    }
    return ret;
  }
};
