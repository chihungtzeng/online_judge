import unittest
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = [nums[0]] * len(nums)
        for i in range(1, len(nums)):
            temp = dp[i-1] + nums[i]
            dp[i] = temp if temp > nums[i] else nums[i]
        return max(dp)

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.maxSubArray([-2, -1]), -1)
        self.assertEqual(sol.maxSubArray([1]), 1)
        self.assertEqual(sol.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]), 6)

if __name__ == "__main__":
    unittest.main()
