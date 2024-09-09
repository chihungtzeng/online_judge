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
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> left, right;
    for (auto v : asteroids) {
      if (v < 0) {
        int vabs = abs(v);
        while (!right.empty() && right.back() < vabs) right.pop_back();
        if (right.empty()) {
          left.push_back(v);
        } else {
          if (right.back() == vabs) right.pop_back();
        }
      } else {
        right.push_back(v);
      }
    }
    vector<int> ret{left.begin(), left.end()};
    for (auto v : right) ret.push_back(v);
    return ret;
  }
};
