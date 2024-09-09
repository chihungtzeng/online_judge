class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        index_dict = {num: idx for idx, num in enumerate(nums)}
        for cur_index, cur_num in enumerate(nums):
            pair = target - cur_num
            if pair in index_dict and index_dict[pair] != cur_index:
                return [cur_index, index_dict[pair]]


if __name__ == "__main__":
    sol = Solution()
    print(sol.twoSum([2, 7, 11, 15], 9))
    print(sol.twoSum([3, 2, 4], 6))
