import unittest
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if not needle:
            return 0
        nlen = len(needle)
        for i in range(len(haystack) - nlen + 1):
            if haystack[i:i+nlen] == needle:
                return i
        return -1

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.strStr("hello", ""), 0)
        self.assertEqual(sol.strStr("hello", "ll"), 2)
        self.assertEqual(sol.strStr("hello", "llo"), 2)
        self.assertEqual(sol.strStr("aaaaa", "bba"), -1)
            
        

if __name__ == "__main__":
    unittest.main()
