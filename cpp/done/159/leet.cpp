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
  int lengthOfLongestSubstringTwoDistinct(string s) {
    unordered_map<char, int> cnt;
    int i = 0, j = 0;
    const int n = s.size();
    if (n <= 2) return n;
    int ans = 0;
    while (i < n && j < n) {
      while (cnt.size() <= 2 && j < n) {
        cnt[s[j]] += 1;
        j++;
        if (cnt.size() <= 2) {
          ans = max(ans, j - i);
        }
      }

      while (cnt.size() >= 3 && i < n) {
        char ch = s[i];
        cnt[ch] -= 1;
        if (cnt[ch] == 0) {
          cnt.erase(ch);
        }
        i++;
      }
    }
    return ans;
  }
};
