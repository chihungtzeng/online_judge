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
  vector<int> nextGreaterElements(vector<int>& nums)
  {
    int n = nums.size();
    nums.reserve(2 * n);
    nums.insert(nums.begin(), nums.begin(), nums.end());
    vector<int> ans(2 * n);
    vector<int> st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
      while (!st.empty() && st.back() <= nums[i])
        st.pop_back();
      ans[i] = st.empty()? -1 : st.back();
      st.push_back(nums[i]);
    }
    ans.erase(ans.begin() + n, ans.end());
    return ans;
  }
};
