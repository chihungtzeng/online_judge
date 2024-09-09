import unittest
class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        m = matrix
        n = len(m)
        if n == 1:
            return
        def swap(r1, c1, r2, c2):
            temp = m[r1][c1]
            m[r1][c1] = m[r2][c2]
            m[r2][c2] = temp
        for r in range(n):
            for c in range(r+1, n):
                swap(r, c, c, r)
        n_1 = n - 1
        for c  in range(n >> 1):
            for r in range(n):
                swap(r, c, r, n_1 -c)

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        matrix = [[1,2,3], [4,5,6], [7,8,9]]
        sol.rotate(matrix)
        self.assertEqual(matrix, [ [7,4,1], [8,5,2], [9,6,3]])

        matrix = [[ 5,1,9,11], [ 2, 4, 8,10], [13, 3, 6, 7], [15,14,12,16] ]
        sol.rotate(matrix)
        self.assertEqual(matrix, [ [15,13, 2, 5], [14, 3, 4, 1], [12, 6, 8, 9], [16, 7,10,11]])

unittest.main()
