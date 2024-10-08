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

using tup = tuple<int, int,
                  bool>;  // location, count, previous_jump(forward or backward)
class Solution {
 public:
  int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    queue<tup> que;             // forward true
    set<pair<int, bool>> seen;  // previous jump direction with its location
    que.push({0, 0, true});
    for (int i : forbidden) seen.insert({i, true}), seen.insert({i, false});
    while (!que.empty()) {
      auto [loc, count, forward] = que.front();
      que.pop();
      if (loc == x)
        return count;
      else if (seen.count({loc, forward}) || loc > 4000)
        continue;
      seen.insert({loc, forward});
      que.push({loc + a, count + 1, true});
      if (forward && loc >= b) que.push({loc - b, count + 1, false});
    }
    return -1;
  }
};
