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
  int countOperations(int n1, int n2)
  {
    int ans = 0;
    while (n1 > 0 && n2 > 0)
    {
      ans += n1 / n2;
      n1 = n1 % n2;
      swap(n1, n2);
    }
    return ans;
  }
};
