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
    string ans;
    string_view sv1 = s1, sv2 = s2;
    while (!sv1.empty() && !sv2.empty()) {
      if (sv1 >= sv2) {
        ans += sv1[0];
        sv1 = sv1.substr(1);
      } else {
        ans += sv2[0];
        sv2 = sv2.substr(1);
      }
    }
    ans += sv1;
    ans += sv2;
    return ans;
  }
};
