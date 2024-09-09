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
  int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    deque<int> q;
    if (x == 0) return 0;

    int ub = 4001;

    vector<bool> redzone(ub, false);
    for (auto f : forbidden) {
        redzone[f] = true;
    }
    set<pair<int, bool>> vis;

    q.push_back(0);
    vis.insert({0, true});
    int dist = 0;
    while (!q.empty()) {
      int qsize = q.size();
      for (int i = 0; i < qsize; i++) {
        int cur = q.front();
        q.pop_front();
        bool is_fwd = (cur >= 0) ? true : false;
        int pos = abs(cur);
        if (x == pos) return dist;

        int next = pos + a;
        pair<int, bool> key{next, true};
        if (next <= ub && !redzone[next] && vis.find(key) == vis.end()) {
          q.push_back(next);
          vis.insert(key);
        }

        next = pos - b;
        key.second = false;
        if (is_fwd && next > 0 && !redzone[next] &&
            vis.find(key) == vis.end()) {
          q.push_back(-next);
          vis.insert(key);
        }
      }
      dist++;
    }
    return -1;
  }
};
