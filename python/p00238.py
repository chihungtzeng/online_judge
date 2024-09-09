import unittest
class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ps = [1] * (len(nums) + 1)
        for i in range(len(nums)-1, 0, -1):
            ps[i] = ps[i+1] * nums[i]
        left = 1
        ps[0] = ps[1]
        for i in range(1, len(nums)):
            left *= nums[i-1]
            ps[i] = left * ps[i+1]
        return ps[0:len(nums)]


class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        nums = [1,2,3,4]
        self.assertEqual(sol.productExceptSelf(nums), [24,12,8,6])
        nums = [3,4]
        self.assertEqual(sol.productExceptSelf(nums), [4, 3])

if __name__ == "__main__":
    unittest.main()
