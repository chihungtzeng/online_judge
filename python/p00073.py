import unittest
class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        if not matrix or not matrix[0]:
            return
        m = len(matrix)
        n = len(matrix[0])
        if matrix[0][0] == 0:
            mark_r0 = True
            mark_c0 = True
        else:
            mark_r0 = False
            mark_c0 = False
        for c in range(1, n):
            if matrix[0][c] == 0:
                matrix[0][c] = float(matrix[0][c])
                mark_r0 = True
        for r in range(1, m):
            if matrix[r][0] == 0:
                matrix[r][0] = float(matrix[r][0])
                mark_c0 = True
        for r in range(1, m):
            for c in range(1, n):
                if matrix[r][c] != 0:
                    continue
                matrix[r][0] = float(matrix[r][0])
                matrix[0][c] = float(matrix[0][c])
        for r in range(1, m):
            if not isinstance(matrix[r][0], float):
                continue
            for c in range(0, n):
                matrix[r][c] = 0
        for c in range(1, n):
            if not isinstance(matrix[0][c], float):
                continue
            for r in range(0, m):
                matrix[r][c] = 0
        if mark_r0:
            for c in range(0, n):
                matrix[0][c] = 0
        if mark_c0:
            for r in range(0, m):
                matrix[r][0] = 0

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        matrix = [ [1,1,1], [1,0,1], [1,1,1] ]
        expected = [ [1,0,1], [0,0,0], [1,0,1] ]
        sol.setZeroes(matrix)
        self.assertEqual(matrix, expected)

        matrix = [ [0,1,2,0], [3,4,5,2], [1,3,1,5] ]
        expected = [ [0,0,0,0], [0,4,5,0], [0,3,1,0] ]
        sol.setZeroes(matrix)
        self.assertEqual(matrix, expected)

        matrix = [ [4,1,2,0], [3,4,5,2], [1,3,1,5] ]
        expected = [ [0,0,0,0], [3,4,5,0], [1,3,1,0] ]
        sol.setZeroes(matrix)
        self.assertEqual(matrix, expected)

unittest.main()
