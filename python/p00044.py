import unittest
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        dp = {}
        dp[(-1, -1)] = True
        for i in range(len(p)):
            dp[(i, -1)] = True if p[i] == "*" and dp[(i-1, -1)] else False
        for j in range(len(s)):
            dp[(-1, j)] = False

        special_chars = ["*", "?"]
        for i in range(len(p)):
            i_1 = i - 1
            for j in range(len(s)):
                j_1 = j - 1
                if p[i] not in special_chars and (p[i] == s[j]) and dp[(i_1, j_1)]:
                    dp[(i, j)] = True
                elif p[i] == "?" and dp[(i_1, j_1)]:
                    dp[(i, j)] = True
                elif p[i] == "*" and (dp[(i_1, j_1)] or dp[(i, j_1)] or dp[(i_1, j)]):
                    dp[(i, j)] = True
                else:
                    dp[(i, j)] = False
        return dp[(len(p) - 1, len(s) - 1)]

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertTrue(sol.isMatch("aa", "*"))
        self.assertTrue(sol.isMatch("adceb", "*a*b"))

        self.assertFalse(sol.isMatch("aa", "a"))
        self.assertFalse(sol.isMatch("cb", "?a"))
        self.assertFalse(sol.isMatch("acdcb", "a*c?b"))

if __name__ == "__main__":
    unittest.main()
