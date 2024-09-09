class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        counts = {}
        for n in nums:
            counts[n] = 1 + counts.get(n, 0)
            if counts[n] == 3:
                counts.pop(n, None)
        for key in counts:
            return key
        
