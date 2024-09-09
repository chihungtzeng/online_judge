import unittest
class Solution(object):
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        lens = len(s)
        if lens < len(t):
            return 0
        prev = 0
        cur = 1
        dp = [[0 for _ in range(lens)] for __ in range(2)]
        dp[cur][0] = 1 if s[0] == t[0] else 0
        for j in range(1, lens):
            dp[cur][j] = dp[cur][j-1] if s[j] != t[0] else dp[cur][j-1] + 1

        for i in range(1, len(t)):
            prev = cur
            cur = 1 - prev
            dp[cur][i] = dp[prev][i-1] if t[i] == s[i] else 0
            for j in range(i+1, lens):
                j_1 = j - 1
                if t[i] == s[j]:
                    dp[cur][j] = dp[prev][j_1] + dp[cur][j_1]
                else:
                    dp[cur][j] = dp[cur][j_1]
        return dp[cur][-1]

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.numDistinct("rabbbit", "rabbit"), 3)
        self.assertEqual(sol.numDistinct("babgbag", "bag"), 5)
        self.assertEqual(sol.numDistinct("aaaa", "aa"), 6)
        self.assertEqual(sol.numDistinct("aaaaa", "aa"), 10)

unittest.main()
