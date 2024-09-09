import unittest
class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        self.board = board
        for r in range(9):
            for c in range(9):
                if board[r][c] == ".":
                    board[r][c] = 0
                else:
                    board[r][c] = int(board[r][c])
        cans = {}
        for r in range(9):
            for c in range(9):
                if board[r][c] == 0:
                    cans[(r,c)] = self.find_cans(r, c)

        while cans:
            stack = [(r,c) for (r,c) in cans if len(cans[(r,c)]) == 1]
            while stack:
                r, c = stack.pop()
                board[r][c] = cans[(r, c)].pop()
                v = board[r][c]
                cans.pop((r, c), None)
                for r_, c_ in self.find_stake_holders(r, c):
                    if (r_, c_) not in cans:
                        continue
                    if v in cans[(r_, c_)]:
                        cans[(r_, c_)].remove(v)
                        if len(cans[(r_, c_)]) == 1:
                            stack.append((r_, c_))
            if cans:
                print(cans)
                break
        for i in range(9):
            for j in range(9):
                board[i][j] = "{}".format(board[i][j])

    def find_cans(self, r, c):
        ret = set(list(range(1, 10)))
        for i in range(9):
            v1 = self.board[r][i]
            v2 = self.board[i][c]
            if v1 > 0 and v1 in ret:
                ret.remove(v1)
            if v2 > 0 and v2 in ret:
                ret.remove(v2)
        r_3 = (r / 3) * 3
        c_3 = (c / 3) * 3
        for i in range(3):
            for j in range(3):
                v = self.board[r_3 + i][c_3 + j]
                if v > 0 and v in ret:
                    ret.remove(v)
        return ret

    def find_stake_holders(self, r, c):
        ret = set()
        for i in range(9):
            ret.add((r, i))
            ret.add((i, c))
        r_3 = (r / 3) * 3
        c_3 = (c / 3) * 3
        for i in range(3):
            for j in range(3):
                ret.add((r_3 + i, c_3 + j))
        ret.remove((r,c))
        return ret


class SolTest(unittest.TestCase):
    def test_1(self):
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
        expected = [
                ["5","3","4","6","7","8","9","1","2"],
                ["6","7","2","1","9","5","3","4","8"],
                ["1","9","8","3","4","2","5","6","7"],
                ["8","5","9","7","6","1","4","2","3"],
                ["4","2","6","8","5","3","7","9","1"],
                ["7","1","3","9","2","4","8","5","6"],
                ["9","6","1","5","3","7","2","8","4"],
                ["2","8","7","4","1","9","6","3","5"],
                ["3","4","5","2","8","6","1","7","9"]]
        sol = Solution()
        sol.solveSudoku(board)
        self.assertEqual(board, expected)

    def test_2(self):
        board= [[".",".","9","7","4","8",".",".","."],["7",".",".",".",".",".",".",".","."],[".","2",".","1",".","9",".",".","."],[".",".","7",".",".",".","2","4","."],[".","6","4",".","1",".","5","9","."],[".","9","8",".",".",".","3",".","."],[".",".",".","8",".","3",".","2","."],[".",".",".",".",".",".",".",".","6"],[".",".",".","2","7","5","9",".","."]]
        expected = [["5","1","9","7","4","8","6","3","2"],["7","8","3","6","5","2","4","1","9"],["4","2","6","1","3","9","8","7","5"],["3","5","7","9","8","6","2","4","1"],["2","6","4","3","1","7","5","9","8"],["1","9","8","5","2","4","3","6","7"],["9","7","5","8","6","3","1","2","4"],["8","3","2","4","9","1","7","5","6"],["6","4","1","2","7","5","9","8","3"]]
        sol = Solution()
        sol.solveSudoku(board)
        print(board)
        self.assertEqual(board, expected)


unittest.main()
