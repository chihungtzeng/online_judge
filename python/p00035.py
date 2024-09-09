import unittest
import bisect
class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        return bisect.bisect_left(nums, target)
        
class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.searchInsert([1,3,5,6], 5), 2)
        self.assertEqual(sol.searchInsert([1,3,5,6], 2), 1)
        self.assertEqual(sol.searchInsert([1,3,5,6], 7), 4)
        self.assertEqual(sol.searchInsert([1,3,5,6], 0), 0)

unittest.main()
