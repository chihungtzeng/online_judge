import unittest
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        last = - 1
        n = len(nums)
        i = 0
        while i < n:
            if nums[i] != val:
                last += 1
                nums[last] = nums[i]
            i += 1
        return last + 1

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        ell = [3,2,2,3]
        self.assertEqual(sol.removeElement(ell, 3), 2)
        self.assertEqual(ell[0:2], [2,2])
        ell = [0,1,2,2,3,0,4,2]
        self.assertEqual(sol.removeElement(ell, 2), 5)
        self.assertEqual(ell[0:5], [0, 1, 3, 0, 4])
        ell = []
        self.assertEqual(sol.removeElement(ell, 2), 0)

unittest.main()
