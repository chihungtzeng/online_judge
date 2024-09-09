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
  vector<int> numsSameConsecDiff(int n, int k)
  {
    using sipair = pair<string, int>;
    vector<vector<int>> diff(10);
    for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 10; j++)
      {
        if (abs(i - j) == k)
          diff[i].push_back(j);
      }
    }
    deque<sipair> q;
    for (int i = 1; i < 10; i++)
    {
      string cur(n, '0');
      cur[0] = i + '0';
      q.push_back({ cur, 0 });
    }
    vector<int> ans;

    while (!q.empty())
    {
      auto [s, idx] = q.front();
      q.pop_front();
      if (idx == n - 1)
      {
        ans.push_back(stoi(s));
      }
      else
      {
        int digit = s[idx] - '0';
        for (auto can : diff[digit])
        {
          s[idx + 1] = can + '0';
          q.push_back({ s, idx + 1 });
        }
      }
    }
    return ans;
  }
};
