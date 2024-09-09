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
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
  {
    const int t = nums1.size() + nums2.size();
    if (t % 2 == 0)
    {
      int v1 = kth(nums1, nums2, t / 2 + 1);
      int v2 = kth(nums1, nums2, t / 2);
      // double m = (v1 + v2) / 2.0;
      // LOG(INFO) << "median: " << m << " from " << pair<int, int>(v1,v2);
      return (v1 + v2) / 2.0;
    }
    else
    {
      int v1 = kth(nums1, nums2, t / 2 + 1);
      // LOG(INFO) << "median: " << v1;
      return (double)v1;
    }
  }

  int kth(vector<int>& nums1, vector<int>& nums2, const int k)
  {
    int left = INT_MAX, right = INT_MIN;
    if (!nums1.empty())
    {
      left = min(left, nums1[0]);
      right = max(right, nums1.back());
    }
    if (!nums2.empty())
    {
      left = min(left, nums2[0]);
      right = max(right, nums2.back());
    }

    while (left <= right)
    {
      int mid = (left + right) / 2;
      int n1 = upper_bound(nums1.begin(), nums1.end(), mid) - nums1.begin();
      int n2 = upper_bound(nums2.begin(), nums2.end(), mid) - nums2.begin();
      int nleq = n1 + n2;
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
};
