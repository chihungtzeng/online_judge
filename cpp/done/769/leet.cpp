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
  int maxChunksToSorted(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    int ans = 0;
    int i = 0;
    while (i < n) {
      int j = next(arr, i);
      ans += 1;
      i = j + 1;
    }
    return ans;
  }
  int next(vector<int>& arr, int i) {
    int j = i;
    if (arr[j] == i) return j;
    j = arr[j];
    for (int k = i + 1; k <= j; k++) {
      j = max(j, arr[k]);
    }
    return j;
  }
};
