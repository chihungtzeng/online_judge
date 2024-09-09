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

using ipair = pair<int, int>;
class Solution {
 public:
  vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    vector<int> cnt(k, 0);
    set<int> avail;
    priority_queue<ipair, vector<ipair>, greater<>> pq;
    int nreq = arrival.size();

    for (int i = 0; i < k; i++) {
      avail.insert(i);
      avail.insert(i + k);
    }

    for (int i = 0; i < nreq; i++) {
      int start = arrival[i];
      int duration = load[i];
      while (!pq.empty() && pq.top().first <= start) {
        auto [last, server_id] = pq.top();
        pq.pop();
        avail.insert(server_id);
        avail.insert(server_id + k);
      }

      if (!avail.empty()) {
        int server_id = (*avail.lower_bound(i % k)) % k;

        avail.erase(server_id);
        avail.erase(server_id + k);
        cnt[server_id] += 1;
        pq.push({start + duration, server_id});
      }
    }

    int peak = *max_element(cnt.begin(), cnt.end());
    vector<int> ans;
    for (int i = 0; i < k; i++) {
      if (cnt[i] == peak) ans.push_back(i);
    }
    return ans;
  }
};
