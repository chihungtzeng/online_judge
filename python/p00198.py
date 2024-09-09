import unittest
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0
        if (n  <= 2):
            return max(nums)
        dp = [0] * n
        profit = 0
        dp[0] = nums[0]
        dp[1] = max(nums[0:2])
        dp[2] = dp[0] + nums[2]
        profit = max(dp[0:3])

        for i in range(3, n):
            dp[i] = max(dp[i-2] + nums[i], dp[i-3] + nums[i])
            if dp[i] > profit:
                profit = dp[i]
        return profit

class SolTest(unittest.TestCase):
    def test_1(self):
        sol =Solution()
        self.assertEqual(sol.rob([1,2,3,1]), 4)
        self.assertEqual(sol.rob([2,7,9,3,1]), 12)
        self.assertEqual(sol.rob([2,1,1,2]), 4)
        self.assertEqual(sol.rob([]), 0)
        self.assertEqual(sol.rob([1,3,1,3,100]), 103)

unittest.main()
