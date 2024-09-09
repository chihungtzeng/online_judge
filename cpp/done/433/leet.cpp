#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 public:
  int minMutation(string start, string end, vector<string>& bank) {
    if (start.size() != end.size()){
      return -1;
    }
    vector<bool> visited(bank.size(), false);
    bool exist = false;
    for(int i=0; i<bank.size(); i++){
      if (bank[i].size() != end.size()){
        visited[i] = true;
      }
      if (end == bank[i]){
        exist = true;
      }
    }
    if (!exist) return -1;
    if (start == end) return 0;
    deque<int> q;
    vector<int> dist(bank.size(), bank.size() + 1);
    for(int i=0; i<bank.size(); i++){
      if (can_mutate(start, bank[i])) {
        q.push_back(i);
        dist[i] = 1;
        visited[i] = true;
      }
    }
    while (!q.empty()){
      auto cur = q.front();
      q.pop_front();
      if (end == bank[cur]){
        return dist[cur];
      }
      for(int i=0; i<bank.size(); i++){
        if (visited[i])
          continue;
        if (can_mutate(bank[cur], bank[i])){
          q.push_back(i);
          visited[i] = true;
          dist[i] = dist[cur] + 1;
        }
      }
    }
    return -1;
  }
  bool can_mutate(const string &s, const string &t){
    int ndiff = 0;
    for(int i=0; i<s.size(); i++){
      if (s[i] != t[i]){
        ndiff++;
      }
      if (ndiff >= 2) return false;
    }
    return bool(ndiff == 1);
  }
};
