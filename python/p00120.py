import unittest
class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        nrows = len(triangle)
        if nrows == 0:
            return 0
        for row in range(1, nrows):
            triangle[row][0] += triangle[row-1][0]
            for col in range(1, row):
                triangle[row][col] += min(triangle[row-1][col-1], triangle[row-1][col])
            triangle[row][row] += triangle[row-1][row-1]
        return min(triangle[nrows-1]) 

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        triangle = [ [2], [3,4], [6,5,7], [4,1,8,3] ]
        print(sol.minimumTotal(triangle))

unittest.main()
