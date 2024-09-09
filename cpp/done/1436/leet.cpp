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
  string destCity(vector<vector<string>>& paths) {
    int ncity = 0;
    unordered_map<string, int> cid;
    unordered_map<int, int> outdegrees;
    vector<string> cities;

    for (auto& path : paths) {
      auto& src = path[0];
      auto& dest = path[1];
      if (cid.find(src) == cid.end()) {
        cid[src] = ncity++;
        cities.push_back(src);
      }
      if (cid.find(dest) == cid.end()) {
        cid[dest] = ncity++;
        cities.push_back(dest);
      }
      outdegrees[cid[src]]++;
      outdegrees[cid[dest]]--;
    }
    for (auto& [id, degree] : outdegrees) {
      if (degree == -1) return cities[id];
    }
    return cities[0];
  }
};
