import unittest
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        sd = {}
        for c in s:
            sd[c] = 1+ sd.get(c,0)
        for c in t:
            if c not in sd:
                return False
            sd[c] -= 1
        for c in sd:
            if sd[c] != 0:
                return False
        return True


class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertTrue(sol.isAnagram("anagram", "nagaram"))
        self.assertFalse(sol.isAnagram("rat", "car"))
        self.assertFalse(sol.isAnagram("ab", "a"))

if __name__ == "__main__":
    unittest.main()
