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

constexpr int head = 1;
constexpr int tail = 0;

class Solution {
 public:
  int leastBricks(vector<vector<int>>& wall) {
    int nrows = wall.size();
    if (nrows == 0) return 0;
    vector<pair<int, int>> segs;
    for(int i=0; i<nrows; i++){
      int pos = 0;
      for(int j=0; j<wall[i].size(); j++){
        segs.emplace_back(pair<int, int>{pos, head});
        pos += wall[i][j];
        segs.emplace_back(pair<int, int>{pos, tail});
      }
      segs.pop_back();
    }
    int cnt = 0;
    int ret = nrows;
    sort(segs.begin(), segs.end());
    for(int i=0; i<segs.size(); i++){
      if (segs[i].second == head){
        cnt += 1;
      } else {
        cnt -= 1;
        ret = min(ret, cnt);
      }
    }
    return ret;
  }
};
