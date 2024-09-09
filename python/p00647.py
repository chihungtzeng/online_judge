import unittest
class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        ell = len(s)
        palindrome = [[0 for _ in range(ell)] for __ in range(ell)]
        for i in range(ell):
            palindrome[i][i] = 1
            if i < ell - 1 and s[i] == s[i+1]:
                palindrome[i][i+1] = 1
        for offset in range(2, ell):
            for i in range(ell):
                end = i + offset
                if end >= ell:
                    continue
                if s[i] == s[end] and palindrome[i+1][end-1] == 1:
                    palindrome[i][end] = 1
        count = 0
        for i in range(ell):
            for j in range(i, ell):
                count += palindrome[i][j]
        return count


class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.countSubstrings("abc"), 3)
        self.assertEqual(sol.countSubstrings("aaa"), 6)
        self.assertEqual(sol.countSubstrings("aaaaa"), 15)

unittest.main()
