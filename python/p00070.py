class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        s = [1] * (n+1)
        for i in range(2, n+1):
            s[i] = s[i-1] + s[i-2]
        return s[n]

sol = Solution()
print(sol.climbStairs(2))
print(sol.climbStairs(3))
