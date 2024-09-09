class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if not nums:
            return []
        nelem = len(nums)
        if nelem == 1:
            return [[nums[0]]]
        ret = []
        seen = set()
        for i in range(nelem):
            if nums[i] in seen:
                continue
            seen.add(nums[i])
            tmp_nums = nums[0:i] + nums[i+1:]
            res = self.permuteUnique(tmp_nums)
            for item in res:
                item.append(nums[i])
                ret.append(item)
        return ret


if __name__ == "__main__":
    sol = Solution()
    print(sol.permuteUnique([1,1,2]))
