import unittest
class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        vt1 = self.ver_tuple(version1)
        vt2 = self.ver_tuple(version2)
        for n1, n2 in zip(vt1, vt2):
            if n1 > n2:
                return 1
            if n1 < n2:
                return -1
        return 0

    def ver_tuple(self, v):
        vt = [int(_) for _ in v.split(".")]
        if len(vt) < 4:
            vt += [0] * (4 - len(vt))
        return vt

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.compareVersion("0.1", "1.1"), -1)
        self.assertEqual(sol.compareVersion("1.0.1", "1"), 1)
        self.assertEqual(sol.compareVersion("7.5.2.4", "7.5.3"), -1)
        self.assertEqual(sol.compareVersion("1.01", "1.001"), 0)

unittest.main()
