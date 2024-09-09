import unittest
class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for zone in self.gen_zones():
            if not self.valid_zone(zone, board):
                return False
        return True

    def gen_zones(self, zones=list()):
        if zones:
            return zones
        for i in range(3):
            for j in range(3):
                zones.append([(3*i+r, 3*j+c) for r in range(3) for c in range(3)])
        for r in range(9):
            zones.append([(r,c) for c in range(9)])
        for c in range(9):
            zones.append([(r,c) for r in range(9)])
        return zones

    def valid_zone(self, zone, board):
        counter = {}
        for r, c in zone:
            v = board[r][c]
            if v != ".":
                counter[v] = 1 + counter.get(v, 0)
        for k in counter:
            if counter[k] > 1:
                return False
        return True

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        board = [
          ["5","3",".",".","7",".",".",".","."],
          ["6",".",".","1","9","5",".",".","."],
          [".","9","8",".",".",".",".","6","."],
          ["8",".",".",".","6",".",".",".","3"],
          ["4",".",".","8",".","3",".",".","1"],
          ["7",".",".",".","2",".",".",".","6"],
          [".","6",".",".",".",".","2","8","."],
          [".",".",".","4","1","9",".",".","5"],
          [".",".",".",".","8",".",".","7","9"]
          ]
        self.assertTrue(sol.isValidSudoku(board))

    def test_2(self):
        sol = Solution()
        board = [
          ["8","3",".",".","7",".",".",".","."],
          ["6",".",".","1","9","5",".",".","."],
          [".","9","8",".",".",".",".","6","."],
          ["8",".",".",".","6",".",".",".","3"],
          ["4",".",".","8",".","3",".",".","1"],
          ["7",".",".",".","2",".",".",".","6"],
          [".","6",".",".",".",".","2","8","."],
          [".",".",".","4","1","9",".",".","5"],
          [".",".",".",".","8",".",".","7","9"]
        ]
        self.assertFalse(sol.isValidSudoku(board))

unittest.main()
