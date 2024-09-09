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
  int numOfMinutes(int n, int headID, vector<int>& manager,
                   vector<int>& informTime) {
    unordered_map<int, vector<int>> subo;
    for (int i = manager.size() - 1; i >= 0; i--) {
      subo[manager[i]].push_back(i);
    }
    subo.erase(subo.find(-1));
    vector<int> delay(n);
    delay[headID] = informTime[headID];
    //    LOG(INFO) << "init delay: " << delay;
    deque<int> q;
    q.push_back(headID);
    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();
      auto it = subo.find(cur);
      if (it == subo.end()) continue;
      for (auto s : subo[cur]) {
        delay[s] = delay[cur] + informTime[s];
        q.push_back(s);
      }
    }
    //    LOG(INFO) << "final delay: " << delay;
    return *max_element(delay.begin(), delay.end());
  }
};
