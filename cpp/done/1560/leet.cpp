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
  vector<int> mostVisited(int n, vector<int>& rounds) {
    vector<int> next(n + 1);
    for (int i = 1; i < n; i++) {
      next[i] = i + 1;
    }
    next[n] = 1;

    vector<int> nvisit(n + 1, 0);
    nvisit[rounds[0]] = 1;
    for (int i = 0; i < rounds.size() - 1; i++) {
      int start = next[rounds[i]];
      int end = next[rounds[i + 1]];
      for (int j = start; j != end; j = next[j]) {
        nvisit[j]++;
      }
    }
    int max_ = *max_element(nvisit.begin() + 1, nvisit.end());
    vector<int> ret;
    for (int i = 1; i <= n; i++) {
      if (nvisit[i] == max_) ret.push_back(i);
    }
    return ret;
  }
};
