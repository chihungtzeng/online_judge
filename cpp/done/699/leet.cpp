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
  vector<int> fallingSquares(vector<vector<int>>& poss)
  {
    vector<int> ans(poss.size(), 0);
    map<ipair, int> seg_h;
    ans[0] = poss[0][1];
    ipair seg = { poss[0][0], poss[0][0] + poss[0][1] };
    seg_h[seg] = poss[0][1];
    for (int i = 1; i < poss.size(); i++)
    {
      auto ht = drop(poss[i], seg_h);
      ans[i] = max(ans[i - 1], ht);
      dump(seg_h);
    }
    return ans;
  }
  void dump(const map<ipair, int>& seg_h)
  {
#ifdef DEBUG
    for (const auto& [seg, h] : seg_h)
    {
      LOG(INFO) << seg << " : " << h;
    }
#endif
  }

  bool overlap(const ipair& a, const ipair& b)
  {
    int l = max(a.first, b.first);
    int r = min(a.second, b.second);
    return  l < r;
  }
  int drop(const vector<int>& pos, map<ipair, int>& seg_h)
  {
    int l = pos[0], h = pos[1], r = pos[0] + pos[1];
    // LOG(INFO) << "drop " << ipair{l, r} << ", height: " << h;
    auto from = seg_h.lower_bound({ l, 0 });
    auto to = seg_h.lower_bound({ r, 0 });
    if (from != seg_h.begin())
    {
      from--;
    }
    int seen_ht = 0;
    ipair cur_seg{ l, r };
    for (auto it = from; it != to; it++)
    {
       if (overlap(it->first, cur_seg))
      //if (it->first.second > l)
      {
        seen_ht = max(seen_ht, it->second);
      }
      else
      {
        // LOG(INFO) << cur_seg << " not intersect with " << it->first;
      }
    }

    auto [l1, r1] = from->first;
    int h1 = from->second;
    int l2 = 0, r2 = 0, h2 = 0;
    if (to != seg_h.begin())
    {
      to--;
      auto seg_to = to->first;
      l2 = seg_to.first;
      r2 = seg_to.second;
      h2 = to->second;
      to++;
    }
    // LOG(INFO) << "l2, r2, h2: " << l2 << ", " << r2 << ", " << h2;
    // LOG(INFO) << "seen_ht: " << seen_ht;
    seg_h.erase(from, to);
    seg_h[cur_seg] = seen_ht + h;
    if (l1 < l)
    {
      // LOG(INFO) << "Add " << ipair{l1, min(l, r1)} << " : " << h1;
      seg_h[{ l1, min(l, r1) }] = h1;
    }
    if (r < r2)
    {
      // LOG(INFO) << "Add " << ipair{r, r2} << " : " << h2;
      seg_h[{ r, r2 }] = h2;
    }
    return seen_ht + h;
  }
};
