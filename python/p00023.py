class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if not lists:
            return None

        import heapq
        ns = []
        for head_node in lists:
            while head_node:
                ns.append((head_node.val, head_node))
                head_node = head_node.next
        if not ns:
            return None
        heapq.heapify(ns)
        value, head_node = heapq.heappop(ns)
        prev_node = head_node
        while ns:
            _v, cur_node = heapq.heappop(ns)
            prev_node.next = cur_node
            prev_node = cur_node
        prev_node.next = None
        return head_node

