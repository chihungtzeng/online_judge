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
  int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    map<int, int> cnt;
    for (auto v : arr) {
      cnt[v] += 1;
    }
    vector<int> vcnt(cnt.size());
    int i = 0;
    for (auto& it : cnt) {
      vcnt[i++] = it.second;
    }
    sort(vcnt.begin(), vcnt.end());
    i = 0;
    while (k > 0 && i < vcnt.size()) {
      if (vcnt[i] < k) {
        k -= vcnt[i];
        i++;
      } else if (vcnt[i] == k) {
        k = 0;
        i++;
      } else {
        k = 0;
      }
    }
    // LOG(INFO) << "vcnt: " << vcnt << " i: " << i;
    return vcnt.size() - i;
  }
};
