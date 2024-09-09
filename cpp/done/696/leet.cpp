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
  int countBinarySubstrings(string s) {
    vector<int> cnt;
    char prev = s[0];
    int cur = 1;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == prev)
        cur++;
      else {
        cnt.push_back(cur);
        cur = 1;
        prev = s[i];
      }
    }
    cnt.push_back(cur);
    int ans = 0;
    for (int i = 1; i < cnt.size(); i++) {
      ans += min(cnt[i - 1], cnt[i]);
    }
    return ans;
  }
};
