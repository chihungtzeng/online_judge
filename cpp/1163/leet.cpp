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
  string lastSubstring(string s) {
    const int n = s.size();
    int i = 0, j = 1, k = 0;
    while (j + k < n) {
      if (s[i + k] == s[j + k])
        k++;
      else if (s[i + k] < s[j + k]) {
        i = j;
        k = 0;
        j++;
      } else {
        j += k+1;
        k = 0;
      }
    }
    return s.substr(i);
  }
};
