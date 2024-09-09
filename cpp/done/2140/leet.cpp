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
  long long mostPoints(vector<vector<int>>& questions)
  {
    int n = questions.size();
    vector<long long> ans(n);
    ans[n - 1] = questions[n - 1][0];
    for (int i = n - 2; i >= 0; i--)
    {
      long long prev = (i + questions[i][1] + 1 < n) ? ans[i + questions[i][1] + 1] : 0;
      ans[i] = max(ans[i + 1], prev + questions[i][0]);
    }
    return ans[0];
  }
};
