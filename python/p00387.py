import unittest
class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return -1
        d = {}
        for i in range(len(s)):
            if s[i] not in d:
                d[s[i]] = (i, False)
            else:
                d[s[i]] = (i, True)
        ret = float("inf")
        for k in d:
            if d[k][1] == False and d[k][0] < ret:
                ret = d[k][0]
        return ret if ret < float("inf") else -1

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.firstUniqChar("leetcode"), 0)
        self.assertEqual(sol.firstUniqChar(""), -1)
        self.assertEqual(sol.firstUniqChar("a"), 0)
        self.assertEqual(sol.firstUniqChar("aa"), -1)
        self.assertEqual(sol.firstUniqChar("loveleetcode"), 2)


if __name__ == "__main__":
    unittest.main()
