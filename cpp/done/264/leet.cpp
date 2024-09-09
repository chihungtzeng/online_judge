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
  int nthUglyNumber(int n)
  {
    set<int> seen;
    priority_queue<uint64_t, vector<uint64_t>, greater<>> min_pq;
    priority_queue<uint64_t> max_pq;
    seen.insert(1);
    min_pq.push(1);
    max_pq.push(1);
    bool done = false;
    while (!done)
    {
      auto cur = min_pq.top();
      min_pq.pop();
      vector<uint64_t> next_ints{ cur << 1, (cur << 1) + cur, (cur << 2) + cur };
      for (auto v : next_ints)
      {
        if (seen.count(v))
          continue;
        min_pq.push(v);
        max_pq.push(v);
        seen.insert(v);
      }
      while (max_pq.size() > n)
        max_pq.pop();
      if (max_pq.size() == n && min_pq.top() > max_pq.top())
      {
        done = true;
      }
    }
    return max_pq.top();
  }
};
