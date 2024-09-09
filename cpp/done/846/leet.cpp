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
  bool isNStraightHand(vector<int>& hand, int W) {
    if (hand.size() % W != 0) return false;

    set<int> vals;

    unordered_map<int, int> cnt;

    for (auto v : hand) {
      auto it = cnt.find(v);
      if (it == cnt.end()) {
        cnt[v] = 1;
        vals.insert(v);
      } else {
        it->second += 1;
      }
    }

    while (!vals.empty()) {
      int smallest = *vals.begin();
      int freq = cnt[smallest];
      for (int i = 0; i < W; i++) {
        cnt[smallest + i] -= freq;
        if (cnt[smallest + i] == 0) {
          cnt.erase(smallest + i);
          vals.erase(smallest + i);
        } else if (cnt[smallest + i] < 0) {
          return false;
        }
      }
    }
    return true;
  }
};
