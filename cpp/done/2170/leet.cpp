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

using ipair = pair<int, int>;
class Solution
{
public:
  int minimumOperations(vector<int>& nums)
  {
    const int n = nums.size();
    if (n <= 1)
      return 0;
    if (n == 2 && nums[0] == nums[1])
      return 1;
    if (n == 2 && nums[0] != nums[1])
      return 0;
    unordered_map<int, int> ecnt, ocnt;
    for (int i = 0; i < n; i += 2)
    {
      ecnt[nums[i]] += 1;
    }
    for (int i = 1; i < n; i += 2)
    {
      ocnt[nums[i]] += 1;
    }
    priority_queue<ipair> epq, opq;
    for (auto& [v, cnt] : ecnt)
    {
      epq.push({ cnt, v });
    }
    for (auto& [v, cnt] : ocnt)
    {
      opq.push({ cnt, v });
    }

    vector<ipair> emax_cnt, omax_cnt;
    for (int i = 0; i < 2 && !epq.empty(); i++)
    {
      emax_cnt.push_back(epq.top());
      epq.pop();
    }
    for (int i = 0; i < 2 && !opq.empty(); i++)
    {
      omax_cnt.push_back(opq.top());
      opq.pop();
    }
    int ans = INT_MAX;
    bool change = false;
    for (int i = 0; i < emax_cnt.size(); i++)
    {
      for (int j = 0; j < omax_cnt.size(); j++)
      {
        if (emax_cnt[i].second == omax_cnt[j].second)
          continue;
        int candidate = n - emax_cnt[i].first - omax_cnt[j].first;
        if (candidate < ans)
        {
          ans = candidate;
          change = true;
        }
        ans = min(ans, candidate);
        // LOG(INFO) << "candidate: " << candidate << ", even change to " << emax_cnt[i].second << ", odd change to " <<
        // omax_cnt[j].second;
      }
    }

    if (change) return ans;
    else return n / 2;
  }
};
