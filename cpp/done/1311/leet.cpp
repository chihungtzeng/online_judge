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
  vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                        vector<vector<int>>& friends, int id,
                                        int level) {
    auto dist = find_dist(friends, id);
    vector<int> foi;
    for (int i = 0; i < friends.size(); i++) {
      if (dist[i] == level) foi.push_back(i);
    }
    unordered_map<string, int> freq;
    for (auto f : foi) {
      for (auto& vdo : watchedVideos[f]) {
        freq[vdo] += 1;
      }
    }

    vector<pair<int, string>> cans;
    for (auto& [name, count] : freq) {
      cans.push_back({count, name});
    }
    sort(cans.begin(), cans.end());

    vector<string> ans;
    for (auto& [_, s] : cans) {
      ans.push_back(s);
    }

    return ans;
  }
  vector<int> find_dist(vector<vector<int>>& friends, int id) {
    vector<int> dist(friends.size(), INT_MAX);
    deque<int> q;
    dist[id] = 0;
    q.push_back(id);
    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();
      for (auto f : friends[cur]) {
        if (dist[f] > 1 + dist[cur]) {
          dist[f] = 1 + dist[cur];
          q.push_back(f);
        }
      }
    }
    return dist;
  }
};
