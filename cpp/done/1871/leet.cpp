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
  bool canReach(string s, int minJump, int maxJump) {
    if (s.back() != '0') return false;

    const int n = s.size();
    vector<bool> seen(n, false);
    seen[0] = true;
    int last_mark = 0;
    deque<int> q;
    q.push_back(0);
    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();
      int ub = cur + maxJump;
      for (int i = max(last_mark, cur + minJump); i <= ub && i < n; i++) {
        if (s[i] == '0') {
          seen[i] = true;
          q.push_back(i);
        }
      }
      last_mark = ub;
    }
    return seen[n - 1];
  }
};
