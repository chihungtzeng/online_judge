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
  void rotate(vector<vector<int>>& matrix)
  {
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
    int cl = 0, cr = n - 1;
    while (cl < cr)
    {
      for (int i = 0; i < n; i++)
      {
        swap(matrix[i][cl], matrix[i][cr]);
      }
      cl++;
      cr--;
    }
  }
};
