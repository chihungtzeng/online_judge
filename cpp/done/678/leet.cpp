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
  bool checkValidString(string s) {
    vector<int> lp, stars;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(')
        lp.push_back(i);
      else if (s[i] == '*')
        stars.push_back(i);
      else if (s[i] == ')') {
        if (!lp.empty())
          lp.pop_back();
        else if (!stars.empty())
          stars.pop_back();
        else
          return false;
      }
    }
    while (!lp.empty()) {
      int lp_idx = lp.back();
      lp.pop_back();
      if (!stars.empty() && stars.back() > lp_idx) {
        stars.pop_back();
      } else {
        return false;
      }
    }
    return true;
  }
};
