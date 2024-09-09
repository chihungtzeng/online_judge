import unittest

from collections import deque
class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        if not board or not board[0]:
            return
        self.nrows = len(board)
        self.ncols = len(board[0])
        self.board = board
        self.neighbors = {}
        for i in range(self.nrows):
            for j in range(self.ncols):
                self.neighbors[(i, j)] = self.neighbor_of((i, j))
        for i in range(self.nrows):
            self.bfs((i, 0))
            self.bfs((i, self.ncols - 1))
        for i in range(self.ncols):
            self.bfs((0, i))
            self.bfs((self.nrows - 1, i))
        for i in range(self.nrows):
            for j in range(self.ncols):
                if self.board[i][j] == "O":
                    self.board[i][j] = "X"
                elif self.board[i][j] == "B":
                    self.board[i][j] = "O"

    def neighbor_of(self, pos):
        cans = [(pos[0] + 1, pos[1]),
                (pos[0] - 1, pos[1]),
                (pos[0], pos[1] + 1),
                (pos[0], pos[1] - 1)]
        return [_ for _ in cans if self.valid_pos(_)]

    def valid_pos(self, pos):
        if pos[0] < 0 or pos[0] >= self.nrows or pos[1] < 0 or pos[1] >= self.ncols:
            return False
        return True

    def bfs(self, pos):
        row, col = pos
        if self.board[row][col] != "O":
            return
        q = deque()
        q.append(pos)
        self.board[row][col] = "B"
        while q:
            row, col = q.popleft()
            for nr, nc in self.neighbors[(row, col)]:
                if self.board[nr][nc] == "O":
                    self.board[nr][nc] = "B"
                    q.append((nr, nc))

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
        expected = [list("XXXX"), list("XXXX"), list("XXXX"), list("XOXX")]
        sol.solve(board)
        self.assertEqual(board, expected)
        board = [list("OOOO")]
        sol.solve(board)
        self.assertEqual(board, [list("OOOO")])
    def test_2(self):
        sol = Solution()
        board = [["O","O","O"],["O","O","O"],["O","O","O"]]
        sol.solve(board)
        self.assertEqual(board, [["O","O","O"],["O","O","O"],["O","O","O"]])
    
unittest.main()
