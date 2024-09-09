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
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> cnt(26);
    for (auto ch : tasks) {
      cnt[ch - 'A'] += 1;
    }
    sort(cnt.begin(), cnt.end());
    int idle_time = (cnt.back() - 1) * n;
    for (int i = 24; i >= 0; i--) {
      int consume = min(idle_time, cnt.back() - 1);
      consume = min(consume, cnt[i]);
      idle_time -= consume;
    }
    return tasks.size() + idle_time;
  }
};
