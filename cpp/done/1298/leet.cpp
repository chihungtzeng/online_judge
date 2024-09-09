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
  int maxCandies(vector<int>& status, vector<int>& candies,
                 vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
                 vector<int>& initialBoxes) {
    deque<int> q;
    int ans = 0;
    int n = status.size();
    vector<int> has_key(n, false);
    vector<bool> vis(n, false);

    for (auto b : initialBoxes) {
      q.push_back(b);
    }

    bool done = false;
    while (!done && !q.empty()) {
      int len = q.size();
      auto org_q = q;
      while (len--) {
        int box_id = q.front();
        q.pop_front();

        if (status[box_id] == 0 && !has_key[box_id]) {
          q.push_back(box_id);
          continue;
        }
        vis[box_id] = true;
        ans += candies[box_id];
        for (auto b : containedBoxes[box_id]) {
          if (!vis[b]) {
            q.push_back(b);
          }
        }
        for (auto b : keys[box_id]) {
          has_key[b] = true;
        }
      }
      if (org_q == q) {
        done = true;
      }
    }

    return ans;
  }
};
