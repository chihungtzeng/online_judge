import unittest
import bisect
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if not nums:
            return -1
        pivot = self.find_pivot(nums)
        index = bisect.bisect_left(nums[:pivot], target)
        if index < len(nums[:pivot]) and nums[index] == target:
            return index
        index = bisect.bisect_left(nums[pivot:], target)
        if index < len(nums[pivot:]) and nums[index + pivot] == target:
            return index + pivot
        return -1

    def find_pivot(self, nums):
        left = 0
        right = len(nums) - 1
        while nums[left] > nums[right]:
            mid = int((left + right) / 2)
            if nums[mid] > nums[left]:
                left = mid
            elif nums[mid] < nums[right]:
                right = mid
            else:
                break
        if left < len(nums) - 1:
            pivot = left + 1 if nums[left] > nums[left+1] else left
        else:
            pivot = 0
        return pivot

class SolTest(unittest.TestCase):
    def __test_1(self):
        sol = Solution()
        n = 100
        nums = list(range(n))
        for pivot in range(0, n+1):
            nums.sort()
            bak = [_ for _ in nums]
            for i in range(n):
                nums[(i+pivot)%n] = bak[i]
            print(nums)
            self.assertEqual(sol.find_pivot(nums), pivot % n)
    def test_1(self):
        sol = Solution()
        nums = [4,5,6,7,0,1,2]
        target = 0
        self.assertEqual(sol.search(nums, target), 4)
        target = 3
        self.assertEqual(sol.search(nums, target), -1)
        nums = []
        target = 0
        self.assertEqual(sol.search(nums, target), -1)
        nums = [100]
        target = 100
        self.assertEqual(sol.search(nums, target), 0)
        nums = [100]
        target = 10
        self.assertEqual(sol.search(nums, target), -1)

unittest.main()
