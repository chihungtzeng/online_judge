import unittest
class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        wsuffix = {}
        for w in wordDict:
            if w[-1] in wsuffix:
                wsuffix[w[-1]].append(w)
            else:
                wsuffix[w[-1]] = [w]
        dp = [False] * (len(s) + 1)
        dp[0] = True
        for i in range(1, len(s) + 1):
            temp = False
            for w in wsuffix.get(s[i-1], []):
                start = i - len(w)
                if start < 0 or not dp[start]:
                    continue
                temp = temp or bool(s[start:i] == w)
            dp[i] = dp[i] or temp
        return dp[len(s)]

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertTrue(sol.wordBreak("leetcode", ["leet", "code"]))
        self.assertTrue(sol.wordBreak("applepenapple", ["apple", "pen"]))

    def test_2(self):
        sol = Solution()
        self.assertFalse(sol.wordBreak("catsandog", ["cats", "dog", "sand", "and", "cat"]))

unittest.main()
