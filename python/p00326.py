class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return bool((n==1) or (n>0 and 1162261467 % n == 0))

sol = Solution()
print(sol.isPowerOfThree(27))
print(sol.isPowerOfThree(0))
print(sol.isPowerOfThree(9))
print(sol.isPowerOfThree(45))
