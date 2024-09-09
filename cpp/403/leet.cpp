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
#define MYDBG 1

class Solution
{
public:
  bool canCross(vector<int>& stones)
  {
    const int n = stones.size();
    vector<set<int>> jrange(n);
    vector<bool> visited(n, false);
    unordered_map<int, int> pos2idx;

    for (int i = 0; i < n; i++)
    {
      pos2idx[stones[i]] = i;
    }

    deque<int> q;

    q.push_back(0);
    jrange[0].insert(0);
    visited[0] = true;

    while (!q.empty())
    {
      int idx = q.front();
      q.pop_front();
      for (auto last_jump : jrange[idx])
      {
        for (int offset = -1; offset <= 1; offset++)
        {
          int jump = last_jump + offset;
          if (jump <= 0)
            continue;

          int next_pos = stones[idx] + jump;
          auto it = pos2idx.find(next_pos);
          if (it == pos2idx.end())
          {
            continue;
          }
          jrange[it->second].insert(jump);
#ifdef MYDBG
          LOG(INFO) << "can jump from " << idx << " to " << it->second << " with " << jump << " steps";
#endif
          if (!visited[it->second])
          {
            visited[it->second] = true;
            q.push_back(it->second);
          }
        }
      }
    }
    return !jrange.back().empty();
  }
};
