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
  string mergeAlternately(string word1, string word2) {
    string ans;
    const int n = word1.size();
    const int m = word2.size();
    const int minmn = min(m, n);
    for (int pos = 0; pos < minmn; pos++) {
      ans.push_back(word1[pos]);
      ans.push_back(word2[pos]);
    }
    if (n > minmn) {
      ans += word1.substr(minmn);
    }
    if (m > minmn) {
      ans += word2.substr(minmn);
    }
    return ans;
  }
};
