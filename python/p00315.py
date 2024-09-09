class Solution(object):
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        import bisect
        ans = []
        s = []
        for n in nums[::-1]:
            index = bisect.bisect_left(s, n)
            ans.append(index)
            s.insert(index, n)
        return list(reversed(ans))

sol = Solution()
print(sol.countSmaller([5,2,6,1]))
