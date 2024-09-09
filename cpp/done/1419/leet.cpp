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
  int minNumberOfFrogs(string croakOfFrogs) {
    unordered_map<char, int> chmap;
    chmap['c'] = 0;
    chmap['r'] = 1;
    chmap['o'] = 2;
    chmap['a'] = 3;
    chmap['k'] = 4;
    vector<deque<int>> chpos(5);
    vector<ipair> segs;
    for (int i = 0; i < croakOfFrogs.size(); i++) {
      int idx = chmap[croakOfFrogs[i]];
      chpos[idx].push_back(i);
      for (int j = 1; j < 5; j++) {
        if (chpos[j - 1].size() < chpos[j].size()) {
          return -1;
        }
      }
      if (idx == 4) {
        for (int j = 0; j < 5; j++) {
          if (chpos[j].empty()) {
            return -1;
          }
        }
        segs.push_back({chpos[0].front(), chpos[4].front()});
        for (int j = 0; j < 5; j++) {
          chpos[j].pop_front();
        }
      }
    }

    for (int i = 0; i < 5; i++) {
      if (!chpos[i].empty()) {
        return -1;
      }
    }
    int ret = 0;
    map<int, int> segs_map;
    for (auto& [start, end] : segs) {
      segs_map[start]++;
      segs_map[end]--;
    }
    int temp = 0;
    for (auto& [pos, occr] : segs_map) {
      temp += occr;
      ret = max(ret, temp);
    }
    return ret;
  }
};
