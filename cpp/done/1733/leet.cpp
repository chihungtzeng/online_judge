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

using ipair = pair<int, int>;
class Solution {
 public:
  int minimumTeachings(int n, vector<vector<int>>& languages,
                       vector<vector<int>>& friendships) {
    int nlang = n;
    int npeople = 0;
    for (auto& v : languages) {
      sort(v.begin(), v.end());
    }
    vector<ipair> need_learnings;
    for (auto& f : friendships) {
      int u = f[0], v = f[1];
      npeople = max(npeople, u);
      npeople = max(npeople, v);
      vector<int> ells(nlang + 1);
      for (auto ul : languages[u - 1]) {
        ells[ul]++;
      }
      bool can_comm = false;
      for (auto vl : languages[v - 1]) {
        if (ells[vl] == 1) {
          can_comm = true;
          break;
        }
      }
      if (!can_comm) {
        need_learnings.emplace_back(u, v);
      }
    }
    int best = npeople;
    for (int ell = 1; ell <= nlang; ell++) {
      vector<int> teached(npeople + 1, 0);
      for (auto& [u, v] : need_learnings) {
        int u1 = u - 1, v1 = v - 1;
        if (!binary_search(languages[u1].begin(), languages[u1].end(), ell) &&
            !teached[u]) {
          teached[u] = 1;
        }
        if (!binary_search(languages[v1].begin(), languages[v1].end(), ell) &&
            !teached[v]) {
          teached[v] = 1;
        }
      }
      best = min(accumulate(teached.begin(), teached.end(), 0), best);
    }
    return best;
  }
};
