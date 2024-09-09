import unittest
class Solution(object):
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0

        n = len(s)
        pt = [[False for _ in range(n)] for __ in range(n)]
        n_1 = n - 1
        for i in range(n):
            pt[i][i] = True
            j = i+1
            if j > n_1:
                break
            pt[i][j] = bool(s[i] == s[j])
        for ell in range(2, n):
            for i in range(n):
                j = ell + i
                if j > n_1:
                    break
                if s[i] == s[j]:
                    pt[i][j] = pt[i+1][j-1]
        dp = [float("inf") for _ in range(n+1)]
        dp[0] = 0

        for i in range(1, n+1):
            for row in range(i):
                if pt[row][i-1]:
                    dp[i] = min(dp[row] + 1, dp[i])
        return dp[-1] - 1

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.minCut("aab"), 1)
        self.assertEqual(sol.minCut("aa"), 0)
        self.assertEqual(sol.minCut("a"), 0)
        self.assertEqual(sol.minCut(""), 0)
        self.assertEqual(sol.minCut("31415"), 2)

    def test_2(self):
        sol = Solution()
        self.assertEqual(sol.minCut("cbbbcc"), 1)

    def test_3(self):
        sol = Solution()
        self.assertEqual(sol.minCut("ccaacabacb"), 3)

unittest.main()
