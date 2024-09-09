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
  int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    unordered_map<char, int> cnt;
    unordered_map<string, int> subs;
    int ans = 0;
    int end = 0, start = 0, n = s.size();
    for (; end < n; end++) {
      cnt[s[end]]++;
      if (end - start + 1 < minSize) continue;

      if (cnt.size() <= maxLetters) {
        string sub = s.substr(start, minSize);
        subs[sub]++;
        ans = max(ans, subs[sub]);
      }
      cnt[s[start]]--;
      if (cnt[s[start]] == 0) {
        cnt.erase(s[start]);
      }
      start++;
    }
    return ans;
  }
};
