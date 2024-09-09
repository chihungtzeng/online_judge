import unittest
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 1:
            return len(nums)
        last = 0
        for i in range(1, len(nums)):
            if nums[i] != nums[last]:
                last += 1
                nums[last] = nums[i]
        return last + 1

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        nums = [1,1,2]
        self.assertEqual(sol.removeDuplicates(nums), 2)
        nums = [0,0,1,1,1,2,2,3,3,4]
        self.assertEqual(sol.removeDuplicates(nums), 5)
        
if __name__ == "__main__":
    unittest.main()
