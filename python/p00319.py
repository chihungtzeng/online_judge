class Solution(object):
    def bulbSwitch(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 0:
            return 0
        ret = 1
        i = 2;
        while i*i <= n:
            ret += 1
            i += 1
        return ret

if __name__ == "__main__":
    sol = Solution()
    print(sol.bulbSwitch(3))
    print(sol.bulbSwitch(4))
    print(sol.bulbSwitch(6))
    print(sol.bulbSwitch(2**32 - 1))
