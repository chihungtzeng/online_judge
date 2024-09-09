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
  vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2)
  {
    if (arr1.size() > arr2.size())
    {
      swap(arr1, arr2);
    }
    reverse(arr1.begin(), arr1.end());
    reverse(arr2.begin(), arr2.end());
    for (int i = 0; i < arr1.size(); i++)
    {
      arr2[i] += arr1[i];
    }
    int sz = arr2.size();
    arr2.push_back(0);
    arr2.push_back(0);

    for (int i = 0; i < sz; i++)
    {
      if (arr2[i] <= 1)
        continue;

      int q = arr2[i] >> 1;
      arr2[i] = arr2[i] & 1;

      int diff = min(q, arr2[i + 1]);
      q -= diff;
      arr2[i + 1] -= diff;

      arr2[i + 1] += q;
      arr2[i + 2] += q;
    }
    while (!arr2.empty() && arr2.back() == 0)
    {
      arr2.pop_back();
    }
    reverse(arr2.begin(), arr2.end());
    if (arr2.empty())
    {
      arr2.push_back(0);
    }
    return arr2;
  }
};
