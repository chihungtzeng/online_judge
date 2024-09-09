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
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    if (people.size() <= 1) return people;
    auto cmp = [](const auto& a, const auto& b) {
      if (a[0] == b[0])
        return a[1] < b[1];
      else
        return a[0] > b[0];
    };
    sort(people.begin(), people.end(), cmp);
    vector<vector<int>> ret;
    ret.push_back(people[0]);
    for (int i = 1; i < people.size(); i++) {
      ret.insert(ret.begin() + people[i][1], people[i]);
    }
    return ret;
  }
};
