import unittest
import pdb
class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if not grid:
            return 0
        if not grid[0]:
            return 0
        parents = {}
        ranks = {}
        nrows = len(grid)
        ncols = len(grid[0])

        def find_set(t):
            if parents[t] != t:
                parents[t] = find_set(parents[t])
            return parents[t]

        def union(t1, t2):
            if find_set(t1) != find_set(t2):
                if ranks[t1] > ranks[t2]:
                    parents[t2] = t1
                elif ranks[t1] == ranks[t2]:
                    parents[t2] = t1
                    ranks[t1] += 1
                else:
                    parents[t2] = t1

        def link_neighbors(t):
            row, col = t[0], t[1]
            candidates = [(row+1, col), (row-1, col), (row, col-1), (row, col+1)]
            ns = [s for s in candidates if s in ranks]
            for t_ in ns:
                nbr_row, nbr_col = t_[0], t_[1]
                if grid[nbr_row][nbr_col] == grid[row][col]:
                    union(find_set(t), find_set(t_))

        for row in range(nrows):
            for col in range(ncols):
                t = (row, col)
                parents[t] = t
                ranks[t] = 0
        for row in range(nrows):
            for col in range(ncols):
                t = (row, col)
                link_neighbors(t)
        ret = 0
        for t in parents:
            row, col = t
            if parents[t] == t and grid[row][col] == "1":
                ret += 1
        return ret

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        grid = [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]
        self.assertEqual(sol.numIslands(grid), 1)
        grid = [list("11000"), list("11000"), list("00100"), list("00011")]
        self.assertEqual(sol.numIslands(grid), 3)
        grid = []
        self.assertEqual(sol.numIslands(grid), 0)

if __name__ == "__main__":
    unittest.main()
