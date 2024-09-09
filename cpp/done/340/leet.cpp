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
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    if (k <= 0) return 0;

    unordered_map<char, int> cnt;
    int i = 0, j = 0, n = s.size();
    int ans = 0;
    while (i < n) {
      cnt[s[i]] += 1;
      if (cnt.size() > k) {
        cnt[s[j]] -= 1;
        if (cnt[s[j]] == 0) {
          cnt.erase(s[j]);
        }
        j++;
      }
      i++;
      ans = max(ans, i - j);
    }
    return ans;
  }
};
