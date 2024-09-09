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

class BIT
{
public:
  vector<int> bit;
  BIT(int size = 0)
  {
    bit.assign(size + 1, 0);
  }

  int get_sum(int idx)
  {
    // get sum in range [1 .. idx]
    int sum = 0;
    for (; idx > 0; idx -= idx & (-idx))
    {
      sum += bit[idx];
    }
    return sum;
  }

  void add_value(int idx, int val)
  {
    for (; idx < bit.size(); idx += idx & (-idx))
    {
      bit[idx] += val;
    }
  }
};

class NumArray
{
  BIT bit;
  vector<int> nums;

public:
  NumArray(vector<int>& nums)
  {
    bit = BIT(nums.size());
    this->nums = nums;
    for (int i = 0; i < nums.size(); i++)
    {
      bit.add_value(i + 1, nums[i]);
    }
  }
  void update(int idx, int val)
  {
    int diff = val = nums[i];
    bit.add_value(idx + 1, diff);
    nums[idx] = val;
  }
  int sum_range(int left, int right)
  {
    return bit.get_sum(right + 1) - bit.get_sum(left);
  }
};
