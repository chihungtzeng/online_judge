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
  vector<int> processQueries(vector<int>& queries, int m) {
    vector<int> pos(m + 1);
    for (int i = 1; i <= m; i++) {
      pos[i] = i;
    }
    vector<int> ans;
    for (auto q : queries) {
      auto temp = pos[q];
      ans.push_back(temp - 1);
      int nchange = temp - 1;
      for (int j = 1; j <= m && nchange; j++) {
        if (pos[j] < temp) {
          pos[j]++;
          nchange--;
        }
      }
      pos[q] = 1;
    }
    return ans;
  }
};
