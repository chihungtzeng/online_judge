import unittest
class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        ret = []
        deps = {}
        in_degree = [0 for _ in range(numCourses)]
        for src, dest in prerequisites:
            if src not in deps:
                deps[src] = [dest]
            else:
                deps[src].append(dest)
            in_degree[dest] += 1
        stack = [_ for _ in range(numCourses) if in_degree[_] == 0]
        while stack:
            src = stack.pop()
            for dest in deps.get(src, []):
                in_degree[dest] -= 1
                if in_degree[dest] == 0:
                    stack.append(dest)
            ret.append(src)
        if len(ret) < numCourses:
            return []
        else:
            ret.reverse()
            return ret

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        print(sol.findOrder(4, [[1,0],[2,0],[3,1],[3,2]]))
        print(sol.findOrder(2, [[1,0]]))
        print(sol.findOrder(3, [[1,0], [2, 1], [0, 2]]))

unittest.main()        
