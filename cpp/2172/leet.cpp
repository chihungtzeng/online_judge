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
  int maximumANDSum(vector<int>& nums, int numSlots)
  {
    return helper(nums, numSlots, 0, 0, 0);
  }
  int helper(const vector<int>& nums, const int nslot, const int idx, const uint64_t cur_state, const int cur_sum)
  {
    if (idx == nums.size()) return cur_sum;
    int res = 0;
    for(int i=1; i<nslot; i++)
    {
      int noccupy = num_occupant_of(cur_state, i);
      if (noccupy >= 2) continue;
      auto state = set_occupant(cur_state, i, noccupy + 1);
      res = max(res, helper(nums, nslot, idx + 1, state, cur_sum + (i & nums[idx])));
    }
    return res;
  }

  int num_occupant_of(const uint64_t state, const int sidx)
  {
    return (state >> (2*sidx)) & 3;
  }

  uint64_t set_occupant(uint64_t state, const int sidx, int noccupant)
  {
    state = set_bit_to_0(state, sidx << 1);
    state = set_bit_to_0(state, 1 + (sidx << 1));
    uint64_t v = static_cast<uint64_t>(noccupant) << (sidx << 1);
    return state ^ v;
  }
  uint64_t set_bit_to_0(uint64_t state, int pos)
  {
    uint64_t mask = ~(1 << pos);
    return state & mask;
  }
};
