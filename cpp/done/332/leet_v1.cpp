#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  unordered_map<string, vector<string>> adj_list_;
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    adj_list_.clear();
    vector<string> route;
    route.reserve(tickets.size() + 1);
    for (const auto& ticket : tickets) {
      adj_list_[ticket[0]].emplace_back(ticket[1]);
    }
    for (auto& item : adj_list_) {
      sort(item.second.begin(), item.second.end());
      reverse(item.second.begin(), item.second.end());
    }
    vector<string> q;
    q.emplace_back("JFK");
    while (!q.empty()) {
      auto city = q.back();
      if (adj_list_[city].empty()) {
        route.emplace_back(city);
        q.pop_back();
      } else {
        q.push_back(adj_list_[city].back());
        adj_list_[city].pop_back();
      }
    }
    reverse(route.begin(), route.end());
    return route;
  }
};
