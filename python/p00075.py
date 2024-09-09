import unittest
class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        counts = [0] * 3
        for i in nums:
            counts[i] += 1
        cur = 0
        for i in range(3):
            while counts[i]:
                nums[cur] = i
                counts[i] -= 1
                cur += 1

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        nums = [2,0,2,1,1,0]
        sol.sortColors(nums)
        self.assertEqual(nums, [0,0,1,1,2,2])

if __name__ == "__main__":
    unittest.main()
