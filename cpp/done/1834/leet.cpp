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
  vector<int> getOrder(vector<vector<int>>& tasks) {
    const int ntasks = tasks.size();
    for (int i = ntasks - 1; i >= 0; i--) {
      tasks[i].push_back(i);
    }
    sort(tasks.begin(), tasks.end());
    priority_queue<ipair, vector<ipair>, greater<>> pq;
    int64_t cur_time = tasks[0][0];
    int i = 0;
    while (i < ntasks && tasks[i][0] <= cur_time) {
      //      LOG(INFO) << "push " << tasks[i][0] << " " << ipair{tasks[i][1],
      //      tasks[i][2]};
      pq.push({tasks[i][1], tasks[i][2]});
      i++;
    }

    vector<int> ret;
    ret.reserve(ntasks);
    while (!pq.empty()) {
      auto [pt, idx] = pq.top();
      //      LOG(INFO) << "pt: " << pt << ", idx: " << idx << ", cur_time: " <<
      //      cur_time;
      pq.pop();
      ret.push_back(idx);
      cur_time += pt;
      if (i < ntasks && cur_time < tasks[i][0] && pq.empty()) {
        cur_time = tasks[i][0];
      }
      //      LOG(INFO) << "cur_time: " << cur_time;
      while (i < ntasks && tasks[i][0] <= cur_time) {
        //        LOG(INFO) << "push " << tasks[i][0] << " " <<
        //        ipair{tasks[i][1], tasks[i][2]};
        pq.push({tasks[i][1], tasks[i][2]});
        i++;
      }
    }
    return ret;
  }
};
