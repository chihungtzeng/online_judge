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
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    vector<bool> overlap(1001, false);

    for (auto v : arr2) {
      overlap[v] = true;
    }
    vector<int> nappear(1001);
    vector<int> q;
    vector<int> ans;
    for (auto v : arr1) {
      if (overlap[v]) {
        nappear[v]++;
      } else {
        q.push_back(v);
      }
    }
    for (auto v : arr2) {
      for (int i = 0; i < nappear[v]; i++) ans.push_back(v);
    }
    sort(q.begin(), q.end());
    ans.insert(ans.end(), q.begin(), q.end());
    return ans;
  }
};
