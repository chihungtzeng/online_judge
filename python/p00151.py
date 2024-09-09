import unittest
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = s.strip()
        res = s.split()
        return " ".join(reversed(res))


class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.reverseWords("the sky is blue"), "blue is sky the")
        self.assertEqual(sol.reverseWords("  hello world!  "), "world! hello")
        self.assertEqual(sol.reverseWords("a good   example"), "example good a")


if __name__ == "__main__":
    unittest.main()
