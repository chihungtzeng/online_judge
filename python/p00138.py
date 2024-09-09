class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if not head:
            return None
        nodes_cc = {None: None}
        cur = head
        while cur:
            cc = Node(cur.val, None, None)
            nodes_cc[cur] = cc
            cur = cur.next
        cur = head
        while cur:
            cc = nodes_cc[cur]
            cc.next = nodes_cc[cur.next]
            cc.random = nodes_cc[cur.random]
            cur = cur.next
        return nodes_cc[head]
