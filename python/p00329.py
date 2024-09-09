import unittest
class Solution(object):
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        m = len(matrix)
        if m == 0:
            return 0
        self.m = m
        n = len(matrix[0])
        if n == 0:
            return 0
        self.n = n
        self.matrix = matrix

        self.nbrs = {}
        self.children = {}
        for row in range(m):
            for col in range(n):
                t = (row, col)
                self.nbrs[t] = self.nbr_tuple(t)
                self.children[t] = [_ for _ in self.nbrs[t] if self.get_value(t) < self.get_value(_)]

        dist = {}
        in_degrees = {t: 0 for t in self.children}
        for t in self.children:
            for child in self.children[t]:
                in_degrees[child] = 1 + in_degrees.get(child, 0)
        queue = [t for t in self.children if in_degrees[t] == 0]
        for t in queue:
            dist[t] = 1
        res = 1
        while queue:
            cur = queue[0]
            queue = queue[1:]
            for child in self.children[cur]:
                in_degrees[child] -= 1
                if in_degrees[child] == 0:
                    queue.append(child)
                    dist[child] = 1 + dist[cur]
                    res = max(res, dist[child])
        return res

    def is_valid_tuple(self, t):
        row, col = t[0], t[1]
        if row < 0 or col < 0 or row >= self.m or col >= self.n:
            return False
        return True

    def nbr_tuple(self, t):
        row, col = t[0], t[1]
        cans = [(row-1, col), (row+1, col), (row, col-1), (row, col+1)]
        return [_ for _ in cans if self.is_valid_tuple(_)]

    def get_value(self, t):
        row, col = t[0], t[1]
        return self.matrix[row][col]

    def is_root(self, t):
        for t_ in self.nbrs[t]:
            if self.get_value(t_) > self.get_value(t):
                return False
        return True

    def dfs(self, t, visited=None):
        depth = 1
        if visited is None:
            visited = {}
        for child in self.children[t]:
            if child not in visited:
                visited[child] = 1
                depth = max(depth, self.dfs(child, visited) + 1)
        return depth


class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        matrix = [ [9,9,4], [6,6,8], [2,1,1] ]
        self.assertEqual(sol.longestIncreasingPath(matrix), 4)
        matrix = [ [3,4,5], [3,2,6], [2,2,1] ]
        self.assertEqual(sol.longestIncreasingPath(matrix), 4)

    def test_2(self):
        sol = Solution()
        matrix = [[0,1,2,3,4,5,6,7,8,9],[19,18,17,16,15,14,13,12,11,10],[20,21,22,23,24,25,26,27,28,29],[39,38,37,36,35,34,33,32,31,30],[40,41,42,43,44,45,46,47,48,49],[59,58,57,56,55,54,53,52,51,50],[60,61,62,63,64,65,66,67,68,69],[79,78,77,76,75,74,73,72,71,70],[80,81,82,83,84,85,86,87,88,89],[99,98,97,96,95,94,93,92,91,90],[100,101,102,103,104,105,106,107,108,109],[119,118,117,116,115,114,113,112,111,110],[120,121,122,123,124,125,126,127,128,129],[139,138,137,136,135,134,133,132,131,130],[0,0,0,0,0,0,0,0,0,0]]
        self.assertEqual(sol.longestIncreasingPath(matrix), 140)

    def test_3(self):
        sol = Solution()
        matrix = [[7,8,9],[9,7,6],[7,2,3]]
        self.assertEqual(sol.longestIncreasingPath(matrix), 6)

if __name__ == "__main__":
    unittest.main()
