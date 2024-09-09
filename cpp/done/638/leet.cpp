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
  int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
  {
    return helper(price, special, needs, special.size() - 1);
  }

  int helper(const vector<int>& price, const vector<vector<int>>& special, const vector<int>& needs, const int idx)
  {
    if (idx < 0)
    {
      return basic_offer(price, needs);
    }
    int ub = max_takes_of(special[idx], needs);
    vector<int> cans(ub + 1);

    for (int ntakes = 0; ntakes <= ub; ntakes++)
    {
      auto cur_needs = needs;
      for (int j = needs.size() - 1; j >= 0; j--)
      {
        cur_needs[j] -= special[idx][j] * ntakes;
      }
      cans[ntakes] = helper(price, special, cur_needs, idx - 1) + special[idx].back() * ntakes;
    }

    return *min_element(cans.begin(), cans.end());
  }

  int basic_offer(const vector<int>& price, const vector<int>& needs)
  {
    int ret = 0;
    for (int i = needs.size() - 1; i >= 0; i--)
    {
      ret += needs[i] * price[i];
    }
    return ret;
  }
  int max_takes_of(const vector<int>& special, const vector<int>& needs)
  {
    int ret = INT_MAX;
    for (int i = needs.size() - 1; i >= 0; i--)
    {
      if (special[i] == 0)
      {
        continue;
      }
      ret = min(ret, needs[i] / special[i]);
    }
    if (ret == INT_MAX)
      ret = 0;
    return ret;
  }
};
