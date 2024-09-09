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
  vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
    priority_queue<ipair, vector<ipair>, greater<>> idle_servers, busy_servers;
    for (int i = servers.size() - 1; i >= 0; i--) {
      idle_servers.push(ipair{servers[i], i});
    }
#if 0
    while(!idle_servers.empty())
    {
      auto s= idle_servers.top();
      LOG(INFO) << s;
      idle_servers.pop();
    }
#endif
    const int ntask = tasks.size();
    vector<int> ans(ntask, -1);
    vector<int> ins_time(ntask);

    for (int i = 0; i < ntask; i++) {
      ins_time[i] = i;
    }

    priority_queue<int, vector<int>, greater<>> timestamps{ins_time.begin(),
                                                           ins_time.end()};

    int task_idx = 0;
    while (!timestamps.empty()) {
      int t = timestamps.top();
      timestamps.pop();
      // end of task timestamps[i].second
      // LOG(INFO) << "time " << t;
      while (!busy_servers.empty() && busy_servers.top().first <= t) {
        int sid = busy_servers.top().second;
        // LOG(INFO) << "release server " << sid;
        idle_servers.push(ipair{servers[sid], sid});
        busy_servers.pop();
      }

      while (!idle_servers.empty() && task_idx < ntask && t >= task_idx) {
        int sid = idle_servers.top().second;
        idle_servers.pop();
        int end_time = max(task_idx, t) + tasks[task_idx];
        busy_servers.push(ipair{end_time, sid});
        // LOG(INFO) << "task " << task_idx << " assign to server " << sid << ",
        // busy until " << end_time;
        timestamps.push(end_time);
        ans[task_idx] = sid;
        task_idx++;
      }
    }
    // CHECK(ans.back() >= 0);
    return ans;
  }
};
