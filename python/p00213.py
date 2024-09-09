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
        if n <= 3:
            return max(nums)
        else:
            return max(self.rob_linear(nums[0:n-1]), self.rob_linear(nums[1:n]))

    def rob_linear(self, nums):
        n = len(nums)
        if n <= 2:
            return max(nums)
        dp = [0] * n
        dp[0] = nums[0]
        dp[1] = max(nums[1], nums[0])
        profit = dp[1]
        for i in range(2, n):
            dp[i] = max(dp[i-1], dp[i-2] + nums[i])
            if dp[i] > profit:
                profit = dp[i]

        return profit

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.rob([2,3,2]), 3)
        self.assertEqual(sol.rob([1, 2,3,1]), 4)
        self.assertEqual(sol.rob([1,1,1,1]), 2)
        self.assertEqual(sol.rob([1,1,1,1,1]), 2)
        self.assertEqual(sol.rob([1,1,1,1,1,1]), 3)
        self.assertEqual(sol.rob([1, 2,3,4]), 6)
        self.assertEqual(sol.rob([1, 2,3,4,5]), 8)
        self.assertEqual(sol.rob([1, 2,3,4,5,6]), 12)
        self.assertEqual(sol.rob([]), 0)
        self.assertEqual(sol.rob([1]), 1)

unittest.main()        
