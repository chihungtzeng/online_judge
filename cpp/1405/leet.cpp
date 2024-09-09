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
using icpair = pair<int, char>;
class Solution {
 public:
  string longestDiverseString(int a, int b, int c) {
    priority_queue<icpair> pq;
    string s;
    pq.push({a, 'a'});
    pq.push({b, 'b'});
    pq.push({c, 'c'});
    bool done = false;
    while (!done) {
      vector<icpair> cur(3);
      for (int i = 0; i < 3; i++) {
        cur[i] = pq.top();
        pq.pop();
      }
      int start = 0;
      if (!s.empty() && s.back() == cur[start].second) start++;

      if (cur[start].first == 0) {
        done = true;
        break;
      }
      int next = start + 1;

      int nelem = min(2, cur[start].first);
      s += string(nelem, cur[start].second);
      cur[start].first -= nelem;
      if (cur[next].first > 0) {
        int nr = min(2, cur[next].first);
        s += string(nr, cur[next].second);
        cur[next].first -= nr;
      }
      for (int i = 0; i < 3; i++) {
        pq.push(cur[i]);
      }
    }

    vector<icpair> cur(3);
    for (int i = 0; i < 3; i++) {
      cur[i] = pq.top();
      pq.pop();
    }
    if (!s.empty() && s.back() != cur[0].second) {
      if (cur[0].first >= 2) {
        s += string(2, cur[0].second);
      } else if (cur[0].first == 1) {
        s += cur[0].second;
      }
    }

    return s;
  }
};
