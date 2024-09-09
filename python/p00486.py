import unittest
class Solution(object):
    def PredictTheWinner(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) <= 2:
            return True
        n = len(nums)
        dp = {}
        for diff in range(n):
            for row in range(n):
                col = row + diff
                if col >= n:
                    continue
                if row == col:
                    dp[(row, col)] = nums[row]
                else:
                    dp[(row, col)] = max(nums[row] - dp[(row + 1, col)], nums[col] - dp[(row, col -1)])
        return bool(dp[(0, n-1)] >= 0)

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertFalse(sol.PredictTheWinner([1, 5, 2]))
        self.assertTrue(sol.PredictTheWinner([1, 5, 233, 7]))

if __name__ == "__main__":
    unittest.main()
