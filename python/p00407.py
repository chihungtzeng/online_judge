import unittest
class Solution(object):
    def trapRainWater(self, heightMap):
        """
        :type heightMap: List[List[int]]
        :rtype: int
        """
        m = len(heightMap)
        if m == 0:
            return 0
        n = len(heightMap[0])
        if n == 0:
            return 0
        lm = {(row, col): 0 for row in range(m) for col in range(n)}
        rm = {(row, col): 0 for row in range(m) for col in range(n)}
        tm = {(row, col): 0 for row in range(m) for col in range(n)}
        bm = {(row, col): 0 for row in range(m) for col in range(n)}
        for row in range(m):
            for col in range(1, n):
                lm[(row, col)] = max(lm[(row, col-1)], heightMap[row][col-1])
            for col in range(n-2, -1, -1):
                rm[(row, col)] = max(rm[(row, col+1)], heightMap[row][col+1])
        for col in range(n):
            for row in range(1, m):
                tm[(row, col)] = max(tm[(row-1, col)], heightMap[row-1][col])
            for row in range(m-2, -1, -1):
                bm[(row, col)] = max(bm[(row+1, col)], heightMap[row+1][col])

        ret = 0
        for row in range(m):
            for col in range(n):
                t = (row, col)
                vol = max(min(lm[t], rm[t], tm[t], bm[t]) - heightMap[row][col], 0)
                if vol > 0:
                    print(t, vol)
                    ret += vol
        return ret

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        height = [ [1,4,3,1,3,2], [3,2,1,3,2,4], [2,3,3,2,3,1] ]
        self.assertEqual(sol.trapRainWater(height), 4)
    def test_2(self):
        sol = Solution()
        height = [[12,13,1,12],[13,4,13,12],[13,8,10,12],[12,13,12,12],[13,13,13,13]]
        self.assertEqual(sol.trapRainWater(height), 14)

unittest.main()
