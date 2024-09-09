import unittest
class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        n = len(gas)
        diff = [gas[i] - cost[i] for i in range(n)]
        if sum(diff) < 0:
            return -1
        _sum = 0
        ret = -1
        for i in range(n):
            _sum += diff[i]
            if diff[i] < 0:
                if _sum < 0:
                    ret = -1
            elif ret == -1:
                ret = i
                _sum = diff[i]
        return ret

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        gas  = [1,2,3,4,5]
        cost = [3,4,5,1,2]
        self.assertEqual(sol.canCompleteCircuit(gas, cost), 3)

        gas  = [2,3,4]
        cost = [3,4,3]
        self.assertEqual(sol.canCompleteCircuit(gas, cost), -1)

unittest.main()
