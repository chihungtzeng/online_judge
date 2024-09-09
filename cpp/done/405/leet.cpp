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
  string toHex(int num) {
    if (num == 0){
      return "0";
    }
    uint32_t t = static_cast<uint32_t>(num);
    string ans;
    while (t > 0) {
      int r = t & 0xf;
      if (r < 10) {
        ans.push_back(r + '0');
      } else {
        ans.push_back(r - 10 + 'a');
      }
      t >>= 4;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
