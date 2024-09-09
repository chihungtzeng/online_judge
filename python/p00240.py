import unittest
class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix:
            return False
        if not matrix[0]:
            return False
        import bisect
        ncol = len(matrix[0])
        for row in matrix:
            if row[0] > target:
                break
            index = bisect.bisect_left(row, target)
            if index < ncol and row[index] == target:
                return True
        return False


class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        matrix = [ [1,   4,  7, 11, 15], [2,   5,  8, 12, 19], [3,   6,  9, 16, 22], [10, 13, 14, 17, 24], [18, 21, 23, 26, 30] ]
        self.assertTrue(sol.searchMatrix(matrix, 5))
        self.assertFalse(sol.searchMatrix(matrix, 20))
        self.assertFalse(sol.searchMatrix([], 0))
        self.assertFalse(sol.searchMatrix([[], []], 0))


if __name__ == "__main__":
    unittest.main()
