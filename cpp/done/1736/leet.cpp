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
  string maximumTime(string time) {
    vector<string> hours, minutes;
    for (int i = 23; i > 0; i--) {
      if (i < 10) {
        hours.push_back("0" + to_string(i));
      } else {
        hours.push_back(to_string(i));
      }
    }
    hours.push_back("00");
    for (int m = 59; m > 0; m--) {
      if (m < 10) {
        minutes.push_back("0" + to_string(m));
      } else {
        minutes.push_back(to_string(m));
      }
    }
    minutes.push_back("00");
    string ans;
    if (time[0] == '?' || time[1] == '?') {
      for (const auto& h : hours) {
        if ((time[0] == h[0] || time[0] == '?') &&
            (time[1] == h[1] || time[1] == '?')) {
          ans += h;
          break;
        }
      }
    } else {
      ans += time.substr(0, 2);
    }
    ans.push_back(':');
    if (time[3] == '?' || time[4] == '?') {
      for (const auto& m : minutes) {
        if ((time[3] == m[0] || time[3] == '?') &&
            (time[4] == m[1] || time[4] == '?')) {
          ans += m;
          break;
        }
      }
    } else {
      ans += time.substr(3, 2);
    }
    return ans;
  }
};
