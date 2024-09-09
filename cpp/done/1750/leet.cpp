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
  int minimumLength(string s) {
    deque<char> q(s.begin(), s.end());
    bool done = false;
    while (!done) {
      if (q.size() <= 1 || (q.front() != q.back())) {
        done = true;
      } else {
        char ch = q.front();
        while (!q.empty() && q.back() == ch) {
          q.pop_back();
        }
        while (!q.empty() && q.front() == ch) {
          q.pop_front();
        }
      }
    }
    return q.size();
  }
};
