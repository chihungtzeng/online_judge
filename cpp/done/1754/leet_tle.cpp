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
  string largestMerge(string s1, string s2) {
    unordered_map<int, string> cache;
    return helper(s1, s2, 0, 0, cache);
  }
  bool same_char(string& s1, string& s2, int i, int j) {
    for (int k = i + 1; k < s1.size(); k++) {
      if (s1[k] != s1[i]) return false;
    }
    for (int k = j; k < s2.size(); k++) {
      if (s2[k] != s1[i]) return false;
    }
    return true;
  }
  string helper(string& s1, string& s2, int i, int j,
                unordered_map<int, string>& cache) {
    int idx = (i << 12) + j;
    auto it = cache.find(idx);
    if (it != cache.end()) {
      return it->second;
    }
    string ans;
    // check if having the same char;
    if (same_char(s1, s2, i, j)) {
      for (int k = i; k < s1.size(); k++) {
        ans += s1[i];
      }
      for (int k = j; k < s2.size(); k++) {
        ans += s2[k];
      }
      cache[idx] = ans;
      return ans;
    }

    while (i < s1.size() && j < s2.size()) {
      if (s1[i] < s2[j]) {
        ans += s2[j++];
      } else if (s1[i] > s2[j]) {
        ans += s1[i++];
      } else {
        ans += s1[i];
        auto c1 = helper(s1, s2, i + 1, j, cache);
        auto c2 = helper(s1, s2, i, j + 1, cache);
        if (c1 > c2) {
          ans += c1;
        } else {
          ans += c2;
        }
        i = s1.size();
        j = s2.size();
      }
    }
    if (i < s1.size()) ans += s1.substr(i);
    if (j < s2.size()) ans += s2.substr(j);
    cache[idx] = ans;
    return ans;
  }
};
