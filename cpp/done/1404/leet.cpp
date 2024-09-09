#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
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
  int numSteps(string s) {
    int ans = 0;
    while (s.size() > 1) {
      while (s.back() == '0') {
        ans++;
        s.pop_back();
      }
      int pos = s.rfind('0');
      if (s == "1") {
        break;
      }
      if (pos == string::npos) {
        ans += s.size() + 1;
        s = "1";
      } else {
        ans += s.size() - pos;
        s = s.substr(0, pos + 1);
        s[pos] = '1';
      }
    }
    return ans;
  }
};
