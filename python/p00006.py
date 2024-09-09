import unittest
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        grid = [["" for _ in range(len(s))] for __ in range(numRows)]
        r = 0
        c = 0
        down = 0
        slope = 1
        nrows_1 = numRows - 1
        direction = down
        if numRows == 1:
            return s
        for char in s:
            grid[r][c] = char
            if direction == down and r < nrows_1:
                r += 1
            elif direction == down and r == nrows_1:
                direction = slope
                r -= 1
                c += 1
            elif direction == slope and r > 0:
                r -= 1
                c += 1
            else:
                direction = down
                r = 1
        ret = []
        for i in range(numRows):
            for j in range(c+1):
                if grid[i][j]:
                    ret.append(grid[i][j])
        return "".join(ret)

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR")
        self.assertEqual(sol.convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI")
        self.assertEqual(sol.convert("PAYPALISHIRING", 1), "PAYPALISHIRING")

unittest.main()
