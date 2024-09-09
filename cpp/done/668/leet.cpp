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
  int findKthNumber(int m, int n, int k)
  {
    if (m > n)
    {
      swap(m, n);
    }
    int left = 1, right = m * n;
    while (left <= right)
    {
      int mid = (left + right) / 2;
      int nleq = count(m, n, mid);
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
  int count(const int m, const int n, const int mid)
  {
    int nleq = 0;
    for (int i = 1; i <= m; i++)
    {
      nleq += min(mid / i, n);
    }
    return nleq;
  }
};
