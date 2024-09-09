# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        if not head:
            return None
        if head and not head.next:
            return TreeNode(head.val)
        middle = self.middle_of(head)
        root = TreeNode(middle.val)
        root.left = self.sortedListToBST(head)
        root.right = self.sortedListToBST(middle.next)
        return root

    def middle_of(self, head):
        slow = head
        fast = head
        pre_slow = None
        while fast and fast.next:
            fast = fast.next.next
            pre_slow = slow
            slow = slow.next
        pre_slow.next = None
        return slow
