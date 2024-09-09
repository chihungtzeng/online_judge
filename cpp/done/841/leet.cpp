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
  bool canVisitAllRooms(vector<vector<int>>& rooms)
  {
    const int n = rooms.size();
    vector<bool> opened(n, false);
    return n == dfs(rooms, opened, 0);
  }
  int dfs(vector<vector<int>>& rooms, vector<bool>& opened, int cur)
  {
    int res = 1;
    opened[cur] = true;
    for (auto room : rooms[cur])
    {
      if (!opened[room])
      {
        res += dfs(rooms, opened, room);
      }
    }
    return res;
  }
};
