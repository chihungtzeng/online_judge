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
  int numberOfRounds(string startTime, string finishTime) {
    auto start = parse(startTime);
    auto end = parse(finishTime);
    if (end[0] < start[0] || (end[0] == start[0] && end[1] < start[1])) {
      end[0] += 24;
    }

    if (start[1] % 15 != 0) {
      start[1] = (1 + start[1] / 15) * 15;
      if (start[1] == 60) {
        start[1] = 0;
        start[0]++;
      }
    }
    if (end[1] % 15 != 0) {
      end[1] = (end[1] / 15) * 15;
    }

    if (end[0] < start[0] || (end[0] == start[0] && end[1] < start[1])) {
      return 0;
    }

    return (end[0] * 4 + end[1] / 15) - (start[0] * 4 + start[1] / 15);
  }
  vector<int> parse(string& ts) {
    string s1 = ts.substr(0, 2);
    string s2 = ts.substr(3, 2);
    return vector<int>{stoi(s1), stoi(s2)};
  }
};
