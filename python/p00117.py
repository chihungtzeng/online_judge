"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution(object):
    def connect(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        from collections import deque
        if not root:
            return None
        prev_node = None
        prev_level = 0
        q = deque()
        q.append((root, 1))
        while q:
            node, level = q.popleft()
            if prev_node and prev_level == level:
                prev_node.next = node
            prev_node = node
            prev_level = level
            if node.left:
                q.append((node.left, level + 1))
            if node.right:
                q.append((node.right, level + 1))
        return root
        
