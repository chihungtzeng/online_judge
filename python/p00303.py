class NumArray(object):
    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.pSum = [0] * (len(nums) + 1)
        for i in range(1, len(nums) + 1):
            i_1 = i - 1
            self.pSum[i] = self.pSum[i_1] + nums[i_1]

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.pSum[j+1] - self.pSum[i]

if __name__ == "__main__":
    sol = NumArray([-2, 0, 3, -5, 2, -1])
    print(sol.sumRange(0, 2))
    print(sol.sumRange(2, 5))
    print(sol.sumRange(0, 5))
