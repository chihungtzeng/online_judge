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
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> stack;
    vector<int> exec_time(n, 0);
    int last_time = 0;
    for (auto& item : logs) {
      int pos = item.find(':');
      int pos2 = item.rfind(':');
      auto status = item.substr(pos + 1, pos2 - pos - 1);
      auto cur_func = stoi(item.substr(0, pos));
      auto cur_time = stoi(item.substr(pos2 + 1));

      if (status.size() == 5) {
        // start
        if (!stack.empty()) {
          auto prev_func = stack.back();
          exec_time[prev_func] += cur_time - last_time;
        }
        stack.push_back(cur_func);
        last_time = cur_time;
      } else if (status.size() == 3) {
        exec_time[cur_func] += cur_time - last_time + 1;
        last_time = cur_time + 1;
        stack.pop_back();
      }
    }
    return exec_time;
  }
};
