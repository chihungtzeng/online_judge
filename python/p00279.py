import unittest
class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        import math
        dp = [0] * max(4, n+1)
        for i in range(1, 4):
            dp[i] = i
        i = 1
        done = False
        squares = {}
        while not done:
            i2 = i * i
            squares[i] = i2
            if i2 > n:
                done = True
            else:
                dp[i2] = 1
            i += 1
        for i in range(5, n+1):
            if dp[i] > 0:
                continue
            res = 5
            done = False
            j = 1
            while not done:
                if squares[j] > i:
                    done = True
                else:
                    j2 = squares[j]
                    res = min(res, dp[j2] + dp[i-j2])
                j += 1
            dp[i] = res
        return dp[n]

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.numSquares(12), 3)
        self.assertEqual(sol.numSquares(13), 2)
        self.assertEqual(sol.numSquares(1), 1)
        self.assertEqual(sol.numSquares(4635), 3)

unittest.main()
