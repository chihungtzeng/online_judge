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

using xyc = tuple<int, int>;
class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int newColor) {
    vector<xyc> stack;
    int rows = image.size();
    int cols = image[0].size();
    int org_color = image[sr][sc];
    if (org_color == newColor){
      return image;
    }
    stack.push_back({sr, sc});
    while (!stack.empty()) {
      auto [r, c] = stack.back();
      stack.pop_back();
      vector<xyc> candidates{{r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1}};
      for (auto [nr, nc] : candidates) {
        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
            image[nr][nc] == org_color) {
          stack.push_back({nr, nc});
        }
      }
      image[r][c] = newColor;
    }
    return image;
  }
};
