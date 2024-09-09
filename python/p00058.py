import unittest
class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        fields = s.strip().split()
        return len(fields[-1]) if len(fields) > 0 else 0

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.lengthOfLastWord("Hello World"), 5)
        self.assertEqual(sol.lengthOfLastWord(""), 0)
        self.assertEqual(sol.lengthOfLastWord(" "), 0)

if __name__ == "__main__":
    unittest.main()
