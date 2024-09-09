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

using ipair = pair<int, int>;
class Solution {
 public:
  vector<string> maxNumOfSubstrings(string s) {
    vector<int> start(26, -1), end(26, -1);
    for (int i = 0; i < s.size(); i++) {
      int idx = s[i] - 'a';
      if (start[idx] < 0) start[idx] = i;
      end[idx] = i;
    }
    vector<ipair> segs;
    for (int i = 0; i < 26; i++) {
      int from = start[i], to = end[i];
      if (from < 0) continue;

      for (int j = from; j < to; j++) {
        int idx = s[j] - 'a';
        //        if (start[idx] > from && start[idx] < to) {
        from = min(from, start[idx]);
        to = max(to, end[idx]);
        //        }
      }
      if (from == start[i]) {
        //        LOG(INFO) << "add (" << to << ", " << from << ") to segs";
        segs.push_back({to, from});
      }
    }
    sort(segs.begin(), segs.end());
    vector<ipair> ret;
    ret.push_back(segs[0]);
    for (int i = 1; i < segs.size(); i++) {
      int from = segs[i].second;
      if (from > ret.back().first) ret.push_back(segs[i]);
    }
    vector<string> ans;
    for (auto& [to, from] : ret) {
      ans.emplace_back(s.substr(from, to - from + 1));
    }
    return ans;
  }
};
