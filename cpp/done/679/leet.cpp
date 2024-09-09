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
#define DEBUG 0

class Solution
{
public:
  bool judgePoint24(vector<int>& cards)
  {
    sort(cards.begin(), cards.end());
    do
    {
      vector<double> rvs{ cards.begin(), cards.end() };
      set<double> op_res;
      find_all_op_res(rvs, op_res, 0);
      for (const auto v : op_res)
      {
        if (abs(v - 24) < 1e-9)
        {
#if DEBUG
          LOG(INFO) << "rvs: " << rvs << ", op_res: " << op_res;

#endif
          return true;
        }
      }
      if (op2x2(rvs))
      {
#if DEBUG
        LOG(INFO) << "op2x2: " << rvs;
#endif
        return true;
      }
    } while (next_permutation(cards.begin(), cards.end()));
    return false;
  }
  bool op2x2(const vector<double>& rvs)
  {
    vector<double> ops[2];
    for (int i = 0; i < 4; i += 2)
    {
      int idx = i / 2;
      auto first = rvs[i];
      auto second = rvs[i + 1];
      ops[idx].push_back(first + second);
      ops[idx].push_back(first - second);
      ops[idx].push_back(first * second);
      ops[idx].push_back(first / second);
    }
    for (auto v1 : ops[0])
    {
      vector<double> res;
      for (auto v2 : ops[1])
      {
        res.push_back(v1 + v2);
        res.push_back(v1 - v2);
        res.push_back(v1 * v2);
        if (v2 != 0)
        {
          res.push_back(v1 / v2);
        }
      }
#if DEBUG
      LOG(INFO) << "v1, " << v1 << ", res: " << res;
#endif
      for (auto r : res)
      {
        if (abs(r - 24) < 1e-9)
          return true;
      }
    }
    return false;
  }
  void find_all_op_res(const vector<double>& rvs, set<double>& op_res, const int idx)
  {
    auto cur = rvs[idx];
    if (idx == rvs.size() - 1)
    {
      op_res.insert(cur);
      return;
    }
    find_all_op_res(rvs, op_res, idx + 1);
    vector<double> addons;
    for (const auto v : op_res)
    {
      addons.push_back(cur + v);
      addons.push_back(cur - v);
      addons.push_back(cur * v);
      if (v != 0)
      {
        addons.push_back(cur / v);
      }
    }
    op_res.clear();
    for (const auto v : addons)
    {
      op_res.insert(v);
    }
  }
};
