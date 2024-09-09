#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int characterReplacement(string s, int k) {
    int ret = 0;
    vector<int> cnt(26);
    for (int start = 0, end = 0; end < s.size(); end++) {
      cnt[s[end] - 'A'] += 1;
      auto max_freq = *max_element(cnt.begin(), cnt.end());
      if (end - start + 1 - max_freq > k) {
        cnt[s[start] - 'A'] -= 1;
        start++;
      } else {
        ret = max(ret, end - start + 1);
      }
    }
    return ret;
  }
};
