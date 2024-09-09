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
  int countTriplets(vector<int>& arr) {
    unordered_map<int, int> pxor;
    unordered_map<int, vector<int>> xor2index;
    pxor[-1] = 0;
    for (int i = 0; i < arr.size(); i++) {
      pxor[i] = pxor[i - 1] ^ arr[i];
      xor2index[pxor[i]].push_back(i);
    }
    int ret = 0;
    for (int i = 0; i < arr.size(); i++) {
      for (int j = i + 1; j < arr.size(); j++) {
        int target = pxor[i - 1];
        auto it = xor2index.find(target);
        if (it == xor2index.end()) {
          continue;
        }
        auto& indexes = it->second;
        auto idx_it = lower_bound(indexes.begin(), indexes.end(), j);
        ret += indexes.size() - (idx_it - indexes.begin());
      }
    }
    return ret;
  }
};
