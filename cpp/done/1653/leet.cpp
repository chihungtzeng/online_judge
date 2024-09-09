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
  int minimumDeletions(string s) {
    int nb = 0;
    int ans = 0;
    for (auto ch : s) {
      if (ch == 'a' && nb > 0) {
        ans++;
        nb--;
      } else if (ch == 'b') {
        nb++;
      }
    }
    return ans;
  }
};
