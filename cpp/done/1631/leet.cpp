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

using ipair = pair<int, int>;
class Solution {
 public:
  int rows, cols;
  const vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
  int minimumEffortPath(vector<vector<int>>& heights) {
    rows = heights.size();
    cols = heights[0].size();
    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
    priority_queue<ipair, vector<ipair>, greater<>> pq;
    dist[0][0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
      auto [d, pos] = pq.top();
      pq.pop();
      int r = pos / cols;
      int c = pos % cols;
      for (int i = 0; i < 4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
          continue;
        }
        // LOG(INFO) << "next:" << nr << ", " << nc << " cur: " << r << ", " <<
        // c;
        int absdiff = abs(heights[nr][nc] - heights[r][c]);
        int can = max(absdiff, dist[r][c]);
        if (can < dist[nr][nc]) {
          dist[nr][nc] = can;
          pq.push({dist[nr][nc], nr * cols + nc});
        }
      }
    }
    return dist[rows - 1][cols - 1];
  }
};
