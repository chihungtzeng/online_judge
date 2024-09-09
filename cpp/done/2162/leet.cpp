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
  int minCostSetTime(int startAt, int moveCost, int pushCost, int target)
  {
    int minute = 0, second = target;
    if (target >= 60)
    {
      minute = target / 60;
      second = target % 60;
    }
    int ans = INT_MAX;
    if (minute < 100)
    {
      auto pat = gen_pat(minute, second);
      ans = min(ans, cost_of(startAt + '0', moveCost, pushCost, pat));
    }

    if (minute > 0 && second + 60 < 100)
    {
      minute--;
      second += 60;
      auto pat = gen_pat(minute, second);

      ans = min(ans, cost_of(startAt + '0', moveCost, pushCost, pat));
    }
    return ans;
  }
  int cost_of(int fpos, int mc, int pc, string& pat)
  {
    int cost = 0;
    for (int i = 0; i < pat.size(); i++)
    {
      if (fpos != pat[i])
        cost += mc;
      cost += pc;
      fpos = pat[i];
    }
    return cost;
  }
  string gen_pat(int minute, int second)
  {
    string ss = to_string(second);
    if (minute > 0 && ss.size() == 1)
    {
      ss = '0' + ss;
    }
    if (minute > 0)
    {
      return to_string(minute) + ss;
    }
    else
    {
      return ss;
    }
  }
};
