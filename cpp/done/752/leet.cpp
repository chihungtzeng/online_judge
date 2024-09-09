#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
  int openLock(vector<string>& deadends, string target)
  {
    unordered_set<string> ds{ deadends.begin(), deadends.end() };
    string cur = "0000";
    if (ds.count(cur))
      return -1;
    unordered_map<string, int> dists;
    dists[cur] = 0;
    deque<string> q;
    q.push_back(cur);
    const vector<int> moves{ 1, -1 };
    while (!q.empty())
    {
      auto cur = q.front();
      auto dist = dists[cur];
      q.pop_front();
      if (cur == target)
      {
        return dist;
      }
      for (int i = 0; i < 4; i++)
      {
        for (auto inc : moves)
        {
          string next = mutate(cur, i, inc);
          if (dists.count(next))
            continue;
          if (ds.count(next))
            continue;
          dists[next] = dist + 1;
          q.emplace_back(next);
        }
      }
    }
    return -1;
  }
  string mutate(string& from, int i, int inc)
  {
    string to = from;
    to[i] = (to[i] - '0' + inc + 10) % 10 + '0';
    return to;
  }
};
