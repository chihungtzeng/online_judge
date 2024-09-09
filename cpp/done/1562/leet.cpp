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
  int findLatestStep(vector<int>& arr, int m) {
    int n = arr.size();
    int ans = -1;
    vector<int> gsize(n + 2, 0);
    unordered_map<int, int> gsize_count;
    for (int i = 0; i < n; i++) {
      int pos = arr[i];
      int g = 1, left = pos, right = pos;
      if (gsize[pos - 1] > 0) {
        left = pos - gsize[pos - 1];
        g += gsize[pos - 1];
        gsize_count[gsize[pos - 1]]--;
      }
      if (gsize[pos + 1] > 0) {
        right = pos + gsize[pos + 1];
        g += gsize[pos + 1];
        gsize_count[gsize[pos + 1]]--;
      }
      gsize[left] = g;
      gsize[right] = g;
      auto it = gsize_count.find(g);
      if (it == gsize_count.end()) {
        gsize_count[g] = 1;
      } else {
        gsize_count[g]++;
      }

      if (gsize_count[m]) {
        ans = i + 1;
      }
    }
    return ans;
  }
};
