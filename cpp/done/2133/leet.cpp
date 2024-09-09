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
  bool checkValid(vector<vector<int>>& matrix)
  {
    const int n = matrix.size();
    string expect(n + 1, 1);
    expect[0] = 0;
    for (int r = 0; r < n; r++)
    {
      string s(n + 1, 0);
      for (int c = 0; c < n; c++)
      {
        s[matrix[r][c]] = 1;
      }
      if (s != expect)
        return false;
    }
    for (int c = 0; c < n; c++)
    {
      string s(n + 1, 0);
      for (int r = 0; r < n; r++)
      {
        s[matrix[r][c]] = 1;
      }
      if (s != expect)
        return false;
    }
    return true;
  }
};
