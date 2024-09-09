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
  long long minimumRemoval(vector<int>& beans)
  {
    const int n = beans.size();
    sort(beans.begin(), beans.end());
    vector<int64_t> psum(n, 0);
    psum[0] = beans[0];
    for (int i = 1; i < n; i++)
    {
      psum[i] = psum[i - 1] + beans[i];
    }
    long long ans = psum.back() - psum[0] - (n - 1) * static_cast<long long>(beans[0]);
    for (int i = 1; i < n; i++)
    {
      if (beans[i] == beans[i - 1])
        continue;
      ans = min(ans, psum[i - 1] + psum.back() - psum[i] - (n - i - 1) * static_cast<long long>(beans[i]));
    }
    return ans;
  }
};
