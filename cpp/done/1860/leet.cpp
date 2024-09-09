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
  vector<int> memLeak(int memory1, int memory2) {
    priority_queue<ipair> pq;
    pq.push(ipair{memory1, -1});
    pq.push(ipair{memory2, -2});
    int tick = 1;
    while (pq.top().first >= tick) {
      auto e = pq.top();
      pq.pop();
      pq.push(ipair{e.first - tick, e.second});
      tick++;
    }
    vector<int> ans(3);
    ans[0] = tick;
    while (!pq.empty()) {
      auto e = pq.top();
      pq.pop();
      ans[-e.second] = e.first;
    }
    return ans;
  }
};
