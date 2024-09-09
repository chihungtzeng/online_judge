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
  int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
    const int n = aliceValues.size();
    vector<ipair> diffs(n);
    for (int i = 0; i < n; i++) {
      diffs[i] = {aliceValues[i] + bobValues[i], i};
    }
    sort(diffs.begin(), diffs.end());
    int alice = 0, bob = 0, turn = 0;
    for (int i = n - 1; i >= 0; i--) {
      int idx = diffs[i].second;
      if (turn == 0) {
        alice += aliceValues[idx];
      } else {
        bob += bobValues[idx];
      }
      turn = 1 - turn;
    }
    if (alice > bob)
      return 1;
    else if (alice == bob)
      return 0;
    else
      return -1;
  }
};
