class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        ret = []
        if numRows == 0:
            return ret
        ret.append([1])
        for row in range(1, numRows):
            ell = [1 for _ in range(row + 1)]
            row_1 = row - 1
            for i in range(1, row):
                ell[i] = ret[row_1][i-1] + ret[row_1][i]
            ret.append(ell)
        return ret

sol = Solution()
print(sol.generate(5))
