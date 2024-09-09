import unittest
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        dp = [0] * (amount + 1)
        for n in coins:
            if n <= amount:
                dp[n] = 1
        for i in range(1, amount + 1):
            if dp[i] > 0:
                continue
            ret = float("inf")
            can_change = False
            for n in coins:
                remain = i - n
                if remain >= 0 and dp[remain] >= 0:
                    ret = min(ret, dp[remain] + 1)
                    can_change = True
            if can_change:
                dp[i] = ret
            else:
                dp[i] = -1
        return dp[amount]

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.coinChange([1, 2, 5], 11), 3)
        self.assertEqual(sol.coinChange([2], 1), -1)
        self.assertEqual(sol.coinChange([2], 2), 1)
        self.assertEqual(sol.coinChange([2], 3), -1)
        self.assertEqual(sol.coinChange([2], 4), 2)

unittest.main()
