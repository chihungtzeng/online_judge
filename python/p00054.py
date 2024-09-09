import unittest
right = 0
down = 1
left = 2
up = 3

class Solution(object):
    def reach_border(self, matrix, r, c, d, m, n):
        if d == right:
            nc = c + 1
            nr = r
        elif d == left:
            nc = c - 1
            nr = r
        elif d == up:
            nc = c
            nr = r - 1
        else:
            nc = c
            nr = r + 1
        if nc < 0 or nc >= n or nr < 0 or nr >= m:
            return True
        elif matrix[nr][nc] is None:
            return True
        else:
            return False

    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        m = len(matrix)
        if m == 0:
            return []
        n = len(matrix[0])
        if n == 0:
            return []
        r = 0
        c = 0
        d = right
        total_steps = m * n
        ret = []
        while len(ret) < total_steps:
            ret.append(matrix[r][c])
            matrix[r][c] = None
            if self.reach_border(matrix, r, c, d, m, n):
                d = (d + 1) % 4
            if d == right:
                c += 1
            elif d == down:
                r += 1
            elif d == left:
                c -= 1
            else:
                r -= 1
        return ret

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        matrix = [ [ 1, 2, 3 ], [ 4, 5, 6 ], [ 7, 8, 9 ]]
        self.assertEqual(sol.spiralOrder(matrix), [1,2,3,6,9,8,7,4,5])
        matrix = [ [1, 2, 3, 4], [5, 6, 7, 8], [9,10,11,12] ]
        self.assertEqual(sol.spiralOrder(matrix), [1,2,3,4,8,12,11,10,9,5,6,7])

unittest.main()
