import unittest
class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if not s:
            return True
        t = [_.lower() for _ in s if _.isalnum()]
        i = 0
        j = len(t) - 1
        while i < j:
            if t[i] != t[j]:
                return False
            i += 1
            j -= 1
        return True

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertTrue(sol.isPalindrome(""))
        self.assertTrue(sol.isPalindrome("A man, a plan, a canal: Panama"))
        self.assertFalse(sol.isPalindrome("race a car"))

unittest.main()
