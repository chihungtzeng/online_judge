#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
  int kthSmallest(vector<vector<int>>& matrix, int k)
  {
    int n = matrix.size();
    int left = matrix[0][0];
    int right = matrix[n - 1][n - 1];
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      int nleq = count(matrix, mid);
      if (nleq >= k)
      {
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }
    return right + 1;
  }

  int count(vector<vector<int>>& matrix, int val)
  {
    int res = 0;
    for (auto& vec : matrix)
    {
      auto it = upper_bound(vec.begin(), vec.end(), val);
      int idx = it - vec.begin();
      res += idx;
    }
    return res;
  }
};
