class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        target = len(nums) / 2
        count = {}
        ret = 0
        for n in nums:
            count[n] = 1 + count.get(n, 0)
            if count[n] > target:
                ret = n
                break
        return ret

sol = Solution()
print(sol.majorityElement([3,2,3]))
print(sol.majorityElement([2,2,1,1,1,2,2]))
