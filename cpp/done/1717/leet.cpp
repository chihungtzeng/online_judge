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
  int maximumGain(string s, int x, int y) {
    int ans = 0;
    if (x > y) {
      ans = x * num_removal_ab(s);
      ans += y * num_removal_ba(s);
    } else {
      ans = y * num_removal_ba(s);
      ans += x * num_removal_ab(s);
    }
    return ans;
  }
  int num_removal_ba(string& s) {
    vector<char> stack;
    int nrm = 0;
    for (auto ch : s) {
      if (!stack.empty() && stack.back() == 'b' && ch == 'a') {
        nrm++;
        stack.pop_back();
      } else {
        stack.push_back(ch);
      }
    }
    s = string(stack.begin(), stack.end());
    return nrm;
  }

  int num_removal_ab(string& s) {
    vector<char> stack;
    int nrm = 0;
    for (auto ch : s) {
      if (!stack.empty() && stack.back() == 'a' && ch == 'b') {
        nrm++;
        stack.pop_back();
      } else {
        stack.push_back(ch);
      }
    }
    s = string(stack.begin(), stack.end());
    return nrm;
  }
};
