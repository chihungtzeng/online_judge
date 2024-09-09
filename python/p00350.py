class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        from collections import Counter
        d1 = Counter(nums1)
        d2 = Counter(nums2)
        ret = []
        for n in d1:
            nelem = min(d1.get(n, 0), d2.get(n, 0))
            ret.extend([n] * nelem)
        return ret


sol = Solution()
nums1 = [1,2,2,1]
nums2 = [2,2]
print(sol.intersect(nums1, nums2))
nums1 = [4,9,5]
nums2 = [9,4,9,8,4]
print(sol.intersect(nums1, nums2))
