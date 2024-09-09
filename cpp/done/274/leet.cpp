#include <algorithm>
#include <cstdint>
#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int hIndex(vector<int> &citations) {
    if (citations.empty()) {
      return 0;
    }
    sort(citations.begin(), citations.end());
    int left = 0, right = citations.back();
    int h = 0;
    while (left <= right)
    {
      auto mid = (left + right) / 2;
      auto low = std::lower_bound(citations.begin(), citations.end(), mid);
      auto nsmaller_than_mid = low - citations.begin();
      int ngeq = citations.size() - nsmaller_than_mid;
      if (ngeq >= mid) {
        left = mid + 1;
        h = max(h, mid);
      } else {
        right = mid - 1;
      }
    }
    return h;
  }
};
