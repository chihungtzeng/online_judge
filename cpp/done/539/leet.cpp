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
  int findMinDifference(vector<string>& tps) {
    vector<int> tps_in_m(tps.size());
    int i = 0;
    for (auto& tp : tps) {
      tps_in_m[i++] = parse(tp);
    }
    int ret = 60 * 24;
    sort(tps_in_m.begin(), tps_in_m.end());
    for (i = 1; i < tps_in_m.size(); i++) {
      ret = min(ret, tps_in_m[i] - tps_in_m[i - 1]);
    }
    ret = min(ret, 1440 + tps_in_m[0] - tps_in_m.back());
    return ret;
  }
  int parse(string& s) {
    int pos = s.find(':');
    int hour = stoi(s.substr(0, pos));
    int minute = stoi(s.substr(pos + 1));
    return 60 * hour + minute;
  }
};
