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
  bool hasAllCodes(string s, int k) {
    unordered_set<string> cnt;
    for (int i = s.size() - k; i >= 0; i--) {
      string sub = s.substr(i, k);
      cnt.insert(sub);
    }
    return bool(cnt.size() == (1 << k));
  }
};
