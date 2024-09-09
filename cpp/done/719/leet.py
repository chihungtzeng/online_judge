from typing import List
class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        def enough(distance) -> bool:  # two pointers
            count, i, j = 0, 0, 0
            while i < n or j < n:
                while j < n and nums[j] - nums[i] <= distance:
                    j += 1
                count += j - i - 1
                i += 1
            return count >= k

        nums.sort()
        n = len(nums)
        left, right = 0, nums[-1] - nums[0]
        while left <= right:
            mid = left + (right - left) // 2
            if not enough(mid):
                left = mid + 1
            else:
                right = mid - 1
        return left

sol = Solution()

def naive(pi, k):
    diffs = []
    for i in range(len(pi)-1):
        for j in range(i+1, len(pi)):
            diffs.append(pi[j] - pi[i])
    diffs.sort()
    return diffs[k-1]

assert sol.smallestDistancePair([1,3,1], 1) == 0
assert sol.smallestDistancePair([1,3,1], 2) == 2
assert sol.smallestDistancePair([1,3,1], 3) == 2
assert sol.smallestDistancePair([1,3,7,3], 1) == 0
assert sol.smallestDistancePair([1,3,7,3], 2) == 2
assert sol.smallestDistancePair([1,3,7,3], 3) == 2
assert sol.smallestDistancePair([1,3,7,3], 4) == 4
assert sol.smallestDistancePair([1,3,7,3], 5) == 4
assert sol.smallestDistancePair([1,3,7,3], 6) == 6
assert naive([1,3, 3,7], 6) == 6
pi = [1,3,10,10,100]
pi.sort()
for i in range(1, len(pi) * (len(pi) -1) // 2 + 1):
    print("naive(pi, {})={}".format(i, naive(pi, i)))
    assert sol.smallestDistancePair(pi, i) == naive(pi, i)
