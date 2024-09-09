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
  int minSetSize(vector<int>& arr) {
    const int n = arr.size();
    unordered_map<int, int> cnt;
    for (auto v : arr) {
      cnt[v] += 1;
    }
    vector<int> vcnt;
    for (auto& [k, v] : cnt) {
      vcnt.push_back(v);
    }
    sort(vcnt.begin(), vcnt.end());
    int nset = 0;
    int bound = (n >> 1) + (n & 1);
    for (int i = vcnt.size() - 1, nrm = 0; i >= 0 && nrm < bound; i--) {
      nrm += vcnt[i];
      nset++;
    }
    return nset;
  }
};

