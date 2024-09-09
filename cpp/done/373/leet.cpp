#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

using ipair = std::pair<int, int>;

class Solution
{
public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
  {
    priority_queue<ipair> pq;
    for (int i = 0; i < nums1.size(); i++)
    {
      int j = 0;
      bool done = false;
      while (j < nums2.size() && !done)
      {
        if (pq.size() == k && pq.top().first < nums1[i] + nums2[j])
        {
          done = true;
        }
        else
        {
          // LOG(INFO) << "push " << ipair{nums1[i], nums2[j]};
          pq.push({ nums1[i] + nums2[j], nums2[j] });
        }
        j++;
        while (pq.size() > k)
        {
          pq.pop();
        }
      }
    }
    vector<vector<int>> res;
    res.reserve(k);
    while (!pq.empty())
    {
      auto [s, n2] = pq.top();
      res.push_back({ s - n2, n2 });
      pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
