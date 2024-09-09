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

class FindSumPairs {
 public:
  map<int, int> m1, m2;
  vector<int> n2;
  FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
    for (auto v : nums1) {
      m1[v]++;
    }
    swap(n2, nums2);
    for (auto v : n2) {
      m2[v]++;
    }
  }

  void add(int index, int val) {
    m2[n2[index]]--;
    n2[index] += val;
    m2[n2[index]]++;
  }

  int count(int tot) {
    int res = 0;
    for (auto& [v, cnt] : m1) {
      int target = tot - v;
      auto it = m2.find(target);
      if (it != m2.end()) {
        res += cnt * it->second;
      }
    }
    return res;
  }
};
