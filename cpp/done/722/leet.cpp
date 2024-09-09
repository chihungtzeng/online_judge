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
  vector<string> removeComments(vector<string>& source) {
    vector<string> res;
    bool block_comment = false;

    string clean_line;
    for (auto& line : source) {
      for (int i = 0, n = line.size(); i < n; i++) {
        if (!block_comment && line[i] == '/' && i < n - 1 &&
            line[i + 1] == '/') {
          break;
        } else if (!block_comment && line[i] == '/' && i < n - 1 &&
                   line[i + 1] == '*') {
          block_comment = true;
          i++;
        } else if (block_comment && line[i] == '*' && i < n - 1 &&
                   line[i + 1] == '/') {
          block_comment = false;
          i++;
        } else if (!block_comment && i < n) {
          clean_line.push_back(line[i]);
        }
      }
      // LOG(INFO) << clean_line;
      if (!clean_line.empty() && !block_comment) {
        res.emplace_back(clean_line);
        clean_line.clear();
      }
    }
    return res;
  }
};
