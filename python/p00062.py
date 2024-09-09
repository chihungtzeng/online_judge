import unittest
class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        npaths = []
        for row in range(n):
            npaths.append([1] * m)
        for row in range(1, n):
            for i in range(1, m):
                npaths[row][i] = npaths[row-1][i] + npaths[row][i-1]
        return npaths[n-1][m-1]


class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.uniquePaths(1, 1), 1)
        self.assertEqual(sol.uniquePaths(1, 3), 1)
        self.assertEqual(sol.uniquePaths(3, 1), 1)
        self.assertEqual(sol.uniquePaths(3, 2), 3)
        self.assertEqual(sol.uniquePaths(7, 3), 28)

if __name__ == "__main__":
    unittest.main()
