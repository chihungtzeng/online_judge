class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        bak = [nums[i] for i in range(len(nums))]
        bak.sort()
        left = 0
        n = len(nums)
        while left < n and bak[left] == nums[left]:
            left += 1
        right = n - 1
        while right >= 0 and bak[right] == nums[right]:
            right -= 1
        if right >= left:
            return right - left + 1
        else:
            return 0

sol = Solution()
print(sol.findUnsortedSubarray([2, 6, 4, 8, 10, 9, 15]))
print(sol.findUnsortedSubarray([1, 2 , 3, 4, 6]))
print(sol.findUnsortedSubarray([]))
print(sol.findUnsortedSubarray([1]))
