#include <vector>
using namespace std;

class Solution
{
public:
  int findPeakElement(vector<int>& nums)
  {
    int n = nums.size();
    if (n <= 1)
      return 0;
    if (nums[0] > nums[1])
      return 0;
    if (nums[n - 1] > nums[n - 2])
      return n - 1;
    int left = 0, right = n - 1;
    while (right - left > 1)
    {
      int mid = (left + right) / 2;
      if (nums[mid] > nums[mid + 1])
      {
        right = mid;
      }
      else
      {
        left = mid;
      }
    }
    return right;
  }
};
