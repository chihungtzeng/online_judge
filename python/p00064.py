import unittest
class Solution(object):
    def minPathSum(self, grid):
        rows = len(grid)
        if rows == 0:
            return 0
        cols = len(grid[0])
        dist = [[0 for _ in range(cols)] for __ in range(rows)]
        dist[0][0] = grid[0][0]
        for c in range(1, cols):
            dist[0][c] = dist[0][c-1] + grid[0][c]
        for r in range(1, rows):
            dist[r][0] = dist[r-1][0] + grid[r][0]
        for r in range(1, rows):
            for c in range(1, cols):
                dist[r][c] = min(dist[r-1][c], dist[r][c-1]) + grid[r][c]
        return dist[rows-1][cols-1]

    def minPathSum2(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        self.m = len(grid)
        if self.m == 0:
            return 0
        self.n = len(grid[0])
        self.queue = [(0, 0)]
        self.grid = grid
        self.dist = {(0, 0): grid[0][0]}

        while self.queue:
            cur_pos = self.queue.pop(0)
            self.update(cur_pos, self.move_down(cur_pos))
            self.update(cur_pos, self.move_right(cur_pos))
        return self.dist[(self.m-1, self.n-1)]

    def update(self, cur_pos, next_pos):
        if not self.is_valid(next_pos):
            return
        nr, nc = next_pos[0], next_pos[1]
        self.dist[next_pos] = min(self.dist.get(next_pos, float("inf")), self.dist[cur_pos] + self.grid[nr][nc])
        self.queue.append(next_pos)

    def move_down(self, pos):
        return (pos[0], pos[1] + 1)

    def move_right(self, pos):
        return (pos[0] + 1, pos[1])

    def is_valid(self, pos):
        return pos[0] >= 0 and pos[0] < self.m and pos[1] >= 0 and pos[1] < self.n

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.minPathSum([[1,3,1], [1,5,1], [4,2,1]]), 7)
        self.assertEqual(sol.minPathSum([[0]]), 0)

    def test_2(self):
        sol = Solution()
        grid = [[7,1,3,5,8,9,9,2,1,9,0,8,3,1,6,6,9,5],[9,5,9,4,0,4,8,8,9,5,7,3,6,6,6,9,1,6],[8,2,9,1,3,1,9,7,2,5,3,1,2,4,8,2,8,8],[6,7,9,8,4,8,3,0,4,0,9,6,6,0,0,5,1,4],[7,1,3,1,8,8,3,1,2,1,5,0,2,1,9,1,1,4],[9,5,4,3,5,6,1,3,6,4,9,7,0,8,0,3,9,9],[1,4,2,5,8,7,7,0,0,7,1,2,1,2,7,7,7,4],[3,9,7,9,5,8,9,5,6,9,8,8,0,1,4,2,8,2],[1,5,2,2,2,5,6,3,9,3,1,7,9,6,8,6,8,3],[5,7,8,3,8,8,3,9,9,8,1,9,2,5,4,7,7,7],[2,3,2,4,8,5,1,7,2,9,5,2,4,2,9,2,8,7],[0,1,6,1,1,0,0,6,5,4,3,4,3,7,9,6,1,9]]

        self.assertEqual(sol.minPathSum(grid), 85)

unittest.main()        
