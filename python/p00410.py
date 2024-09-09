import unittest
class Solution(object):
    def splitArray(self, nums, m):
        """
        :type nums: List[int]
        :type m: int
        :rtype: int
        """
        left = 0
        right = len(nums) * max(nums)
        ret = right
        while left <= right:
            mid = (left + right) >> 1
            if self.can_split(nums, m, mid):
                ret = min(ret, mid)
                right = mid - 1
            else:
                left = mid + 1
        return ret
    def can_split(self, nums, m, mid):
        pSum = 0
        for n in nums:
            if n > mid:
                return False
            pSum += n
            if pSum > mid:
                pSum = n
                m -= 1
                if m == 0:
                    return False
        return True



class SolTest(unittest.TestCase):
    def test_0(self):
        sol = Solution()
        self.assertTrue(sol.can_split([7,2,5,10,8], 5, 10))
        self.assertFalse(sol.can_split([7,2,5,10,8], 5, 9))
        
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.splitArray([7,2,5,10,8], 2), 18)
        self.assertEqual(sol.splitArray([7,2,5,10,8], 5), 10)
        self.assertEqual(sol.splitArray([7,2,5,10,8], 1), 32)
    def test_2(self):
        sol = Solution()
        self.assertEqual(sol.splitArray([1,2147483647], 2), 2147483647)

unittest.main()

