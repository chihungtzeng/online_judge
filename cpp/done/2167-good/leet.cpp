#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <queue>
using namespace std;

class Solution
{
public:
  int minimumTime(string s)
  {
    int n = s.size();
    return n + helper(s);
  }
  int helper(const string& s)
  {
    int best = 0, cur = 0;
    for (auto ch : s)
    {
      int val = ((ch - '0') << 1) - 1;
      cur = min(cur + val, val);
      best = min(cur, best);
    }
    return best;
  }
};
