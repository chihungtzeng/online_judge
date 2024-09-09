import unittest

class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        right, down, left, up = 0, 1, 2, 3
        m = [[0 for _ in range(n)] for __ in range(n)]

        def next_pos(row, col, dir_):
            if dir_ == left:
                return row, col-1
            if dir_ == right:
                return row, col+1
            if dir_ == up:
                return row-1, col
            if dir_ == down:
                return row+1, col

        def next_dir(row, col, dir_):
            row_, col_ = next_pos(row, col, dir_)
            if row_ >= 0 and row_ < n and col_ >= 0 and col_ < n and m[row_][col_] == 0:
                return dir_
            return (dir_ + 1) % 4

        value = 1
        dir_ = right
        row, col = 0, 0
        nsteps = n*n
        while value <= nsteps:
            m[row][col] = value
            value += 1
            row, col = next_pos(row, col, dir_)
            dir_ = next_dir(row, col, dir_)
        return m

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        for i in range(3, 9):
            ret = sol.generateMatrix(i)
            for row in range(len(ret)):
                print(ret[row])
            print("")

if __name__ == "__main__":
    unittest.main()
