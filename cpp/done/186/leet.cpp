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
  void reverseWords(vector<char>& s) {
    reverse(s.begin(), s.end());
    int i = 0, j = 0;
    const int n = s.size();
    while (i < n && j < n) {
      while (j < n && s[j] != ' ') j++;
      reverse(s.begin() + i, s.begin() + j);
      i = j + 1;
      j++;
    }
    if (i < n) {
      reverse(s.begin() + i, s.end());
    }
  }
};
