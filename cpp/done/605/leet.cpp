#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
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
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int nallow = 0;
    flowerbed.insert(flowerbed.begin(), 0);
    flowerbed.push_back(0);
    for (int i = flowerbed.size() - 2; i >= 1; i--) {
      if (flowerbed[i] == 0 && flowerbed[i + 1] == 0 && flowerbed[i - 1] == 0) {
        nallow++;
        flowerbed[i] = 1;
      }
    }
    return bool(nallow >= n);
  }
};
