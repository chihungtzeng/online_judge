class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        return (n*(n+1) >> 1) - sum(nums)

sol = Solution()
print(sol.missingNumber([9,6,4,2,3,5,7,0,1]))
