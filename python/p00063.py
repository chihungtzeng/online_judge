import unittest
class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        obs = obstacleGrid
        m = len(obs)
        n = len(obs[0])
        if obs[m-1][n-1] == 1:
            return 0
        nsteps = [[0 for _ in range(n)] for __ in range(m)]
        nsteps[0][0] = 1 - obs[0][0]
        for row in range(1, m):
            if obs[row][0]:
                nsteps[row][0] = 0
            else:
                nsteps[row][0] = nsteps[row-1][0]
        for col in range(1, n):
            nsteps[0][col] = 0 if obs[0][col] else nsteps[0][col-1]
        for row in range(1, m):
            row_1 = row - 1
            for col in range(1, n):
                col_1 = col - 1
                nsteps[row][col] = (1-obs[row_1][col]) * nsteps[row_1][col] + (1-obs[row][col_1])*nsteps[row][col_1]
        return nsteps[m-1][n-1]


class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        grid = [ [0,0,0], [0,1,0], [0,0,0] ]
        self.assertEqual(sol.uniquePathsWithObstacles(grid), 2)
        grid = [[1]]
        self.assertEqual(sol.uniquePathsWithObstacles(grid), 0)
        grid = [[0,0],[0,1]]
        self.assertEqual(sol.uniquePathsWithObstacles(grid), 0)

if __name__ == "__main__":
    unittest.main()
