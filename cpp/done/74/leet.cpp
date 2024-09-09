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
  bool searchMatrix(vector<vector<int>>& matrix, int target)
  {
    int m = matrix.size() - 1;
    int from = max(0, find_start_row(matrix, target));
    int to = min(m, find_end_row(matrix, target));
    //    LOG(INFO) << "from " << from << " to " << to;
    for (int i = from; i <= to; i++)
    {
      if (binary_search(matrix[i].begin(), matrix[i].end(), target))
        return true;
    }
    return false;
  }

  int find_start_row(vector<vector<int>>& matrix, int target)
  {
    int left = 0, right = matrix.size() - 1;
    while (left <= right)
    {
      int mid = (left + right) / 2;
      if (matrix[mid][0] >= target)
      {
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }
    return left - 1;
  }

  int find_end_row(vector<vector<int>>& matrix, int target)
  {
    int left = 0, right = matrix.size() - 1;
    int col = matrix[0].size() - 1;
    while (left <= right)
    {
      int mid = (left + right) / 2;
      if (matrix[mid][col] >= target)
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
};
