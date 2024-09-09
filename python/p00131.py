import unittest
class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        if not s:
            return [[]]
        if len(s) == 1:
            return [[s]]
        pas = [s[:end] for end in range(1, len(s) + 1) if self.is_palindrom(s[:end])]
        ret = []
        for ps in pas:
            for tps in self.partition(s[len(ps):]):
                ret.append([ps] + tps)
        return ret

    def is_palindrom(self, s):
        i = 0
        j = len(s) - 1
        while i < j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sorted(sol.partition("aab")), sorted([["aa","b"], ["a","a","b"]]))

    def test_2(self):
        sol = Solution()
        #print(sol.partition("31415"))
        self.assertEqual(sorted(sol.partition("bb")), sorted([["bb"], ["b","b"]]))

unittest.main()
