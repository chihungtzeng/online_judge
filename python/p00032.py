import unittest
class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        lens = len(s)
        def is_valid(start, ell):
            if ell <= 0:
                return False
            if ell & 1:
                return False
            end = start + ell - 1
            if end >= lens:
                return False
            pos = (start, ell)
            if pos in cache:
                return cache[pos]
            if s[start] != "(" or s[end] != ")":
                ret = False
            elif ell == 2:
                ret = True
            else:
                ret = is_valid(start, ell - 2)

            cache[pos] = ret
            return ret

        cache = {}
        if lens & 1:
            start_ell = lens - 1
        else:
            start_ell = lens

        for ell in range(start_ell, 0, -2):
            for start in range(lens):
                if is_valid(start, ell):
                    return ell
        return 0

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.longestValidParentheses("()(())"), 6)
        self.assertEqual(sol.longestValidParentheses("(()"), 2)
        self.assertEqual(sol.longestValidParentheses(")()())"), 4)

if __name__ == "__main__":
    unittest.main()
