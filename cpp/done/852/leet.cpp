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
  int peakIndexInMountainArray(vector<int>& arr)
  {
    int left = 0, right = arr.size() - 1;
    while (right - left > 1)
    {
      int mid = (left + right) / 2;
      if (arr[mid] < arr[mid + 1])
      {
        left = mid;
      }
      else
      {
        right = mid;
      }
    }
    if (arr[left] > arr[right])
      return left;
    else
      return right;
  }
};
