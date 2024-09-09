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
  bool canConstruct(string s, int k) {
    vector<int> cnt(26);
    for (auto ch : s) {
      cnt[ch - 'a']++;
    }
    int nodd = 0;
    for (auto c : cnt) {
      if (c % 2 == 1) nodd++;
    }
    if (nodd > k) return false;
    k -= nodd;
    int nremains = s.size() - nodd;
    if (nremains < k) {
      return false;
    }
    return true;
  }
};
