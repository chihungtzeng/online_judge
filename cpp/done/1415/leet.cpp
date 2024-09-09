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
  string getHappyString(int n, int k) {
    vector<string> cans;
    deque<string> q{"a", "b", "c"};
    while (!q.empty()) {
      auto s = q.front();
      q.pop_front();
      if (s.size() == n) {
        cans.emplace_back(s);
        continue;
      }
      if (s.back() == 'a') {
        q.push_back(s + 'b');
        q.push_back(s + 'c');
      }
      if (s.back() == 'b') {
        q.push_back(s + 'a');
        q.push_back(s + 'c');
      }
      if (s.back() == 'c') {
        q.push_back(s + 'a');
        q.push_back(s + 'b');
      }
    }
    if (k <= cans.size()) {
      return cans[k - 1];
    }
    return "";
  }
};
