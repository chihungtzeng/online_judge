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
  vector<int> pathInZigZagTree(int label) {
    int level = 0;
    vector<int> ans;
    while ((1 << level) < label) {
      level++;
    }
    level--;
    while (level >= 1) {
      ans.push_back(label);
      int parent_order = (label - (1 << level)) / 2;
      LOG(INFO) << "label: " << label << ", level: " << level << ", parent_order:" << parent_order;
      label = (1 << level) - 1 - parent_order;
      level--;
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
